#include <iostream>
#include <string>


// Product class
class Computer {
public:
	void setCPU(const std::string& cpu) {
		cpu_ = cpu;
	}

	void setMemory(const std::string& memory) {
		memory_ = memory;
	}

	void setStorage(const std::string& storage) {
		storage_ = storage;
	}

	void setBattery(const std::string& battery) {
		battery_ = battery;
	}

	void display() {
		std::cout << "CPU: " << cpu_ << std::endl;
		std::cout << "Memory: " << memory_ << std::endl;
		std::cout << "Storage: " << storage_ << std::endl;
		std::cout << "Battery: " << battery_ << std::endl;
	}

private:
	std::string cpu_;
	std::string memory_;
	std::string storage_;
	std::string battery_;
};



// Builder interface
class ComputerBuilder {
public:
	virtual void buildCPU(const std::string& cpu) = 0;
	virtual void buildMemory(const std::string& memory) = 0;
	virtual void buildStorage(const std::string& storage) = 0;
	virtual Computer getResult() = 0;
};


// Concrete Builder
class DesktopComputerBuilder : public ComputerBuilder {
public:
	DesktopComputerBuilder() {
		computer_ = Computer();
	}

	void buildCPU(const std::string& cpu) override {
		computer_.setCPU(cpu);
	}

	void buildMemory(const std::string& memory) override {
		computer_.setMemory(memory);
	}

	void buildStorage(const std::string& storage) override {
		computer_.setStorage(storage);
	}

	void buildBattery(const std::string& battery) {
		computer_.setBattery(battery);
	}

	Computer getResult() override {
		return computer_;
	}
	

private:
	Computer computer_;
};


class ComputerAssembler {
public:
	Computer assembleComputer(ComputerBuilder& builder) {
		builder.buildCPU("Intel i7");
		builder.buildMemory("16GB");
		builder.buildStorage("512GB SSD");
		return builder.getResult();
	}
	Computer assembleAdamLaptop(DesktopComputerBuilder& builder) {
		builder.buildCPU("Intel Core i5-3320M");
		builder.buildMemory("4GB");
		builder.buildStorage("256GB HDD");
		builder.buildBattery("Yes");
		return builder.getResult();
	}
};


int main() {
	DesktopComputerBuilder desktopBuilder;
	ComputerAssembler assembler;
	Computer desktop = assembler.assembleComputer(desktopBuilder);
	std::cout << "Desktop Computer Configuration:" << std::endl;
	desktop.display();

	Computer laptop = assembler.assembleAdamLaptop(desktopBuilder);
	std::cout << "Laptop Adasia: \n";
	laptop.display();

	return 0;
}
