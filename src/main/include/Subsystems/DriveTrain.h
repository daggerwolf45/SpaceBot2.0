// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "rev/CANSparkMax.h"
#include "ctre/Phoenix.h"
#include "OI.h"
#include "networktables/NetworkTable.h"
#include "time.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "PIDHelper/GyroPID.h"
#include "PIDHelper/RotatePID.h"
/**
 *
 *
 * @author ExampleAuthor
 */

#define PRESSURE_SENSOR_OFFSET 4.0
#define VISION_TARGET_MARGIN_ERROR 0.1

#define TURN_PID_P 0.01
#define TURN_PID_I 0.0
#define TURN_PID_D 0.001
#define TURN_PID_F 0.0
#define TURN_PID_TOLERANCE 2.0
#define TURN_MAX_SPEED 0.4

class DriveTrain: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<rev::CANSparkMax> sparkMX_L1;
	std::shared_ptr<rev::CANSparkMax> sparkMX_L2;
	std::shared_ptr<frc::SpeedControllerGroup> scg_1;
	std::shared_ptr<rev::CANSparkMax> sparkMX_R1;
	std::shared_ptr<rev::CANSparkMax> sparkMX_R2;
	std::shared_ptr<frc::SpeedControllerGroup> scg_2;
	std::shared_ptr<frc::DifferentialDrive> robotDrive;
	std::shared_ptr<frc::PowerDistributionPanel> pdp;
	std::shared_ptr<PigeonIMU> pigeon;
	std::shared_ptr<frc::Compressor> compressor;
	std::shared_ptr<frc::AnalogInput> pressureSensor;
	std::shared_ptr<frc::DoubleSolenoid> climbSolenoid;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	GyroPID* gyroSource;
	RotatePID* rotateOutput;

	frc::PIDController* turnPID;
	void InitTurnPID();

	std::shared_ptr<NetworkTable> networkTable;
	std::vector<double> xVals;
	std::vector<double> yVals;

public:
	DriveTrain();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void SetTurnPIDEnabled(bool enable);
	void SetTurnPIDSetpoint(double angle);
	bool TurnPIDOnTarget();
	void TankDrive(double l, double r);
	void ArcadeDrive(double speed, double rotation);
	void SetBrakeMode();
	void SetCoastMode();
	void RotateRobot(double mag);
	void SetClimbSolenoid(bool up);
	double GetVisionTargetOffset();
	double GetGyroBearing();
	void Stop();
	double GetPDPChannelCurrent(int channel);
	double GetPressure();
	void DisplayDrivetrainSensors();

};

#endif
