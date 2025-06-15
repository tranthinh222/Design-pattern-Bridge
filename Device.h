#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <iostream>
#include <string>

using namespace std;

// ============================================
// Abstract interface for all controllable devices
// ============================================
// This serves as the "Implementor" in the Bridge Design Pattern.
// Concrete devices (TV, Radio, Speaker) implement this interface.
class Device {
public:
    // Check if the device is currently powered on
    virtual bool isEnabled() const = 0;

    // Turn the device on
    virtual void enable() = 0;

    // Turn the device off
    virtual void disable() = 0;

    // Get the current volume (0–100)
    virtual int getVolume() const = 0;

    // Set the device volume (clamped between 0–100)
    virtual void setVolume(int percent) = 0;

    // Get the current channel/frequency
    virtual int getChannel() const = 0;

    // Change the channel/frequency
    virtual void setChannel(int channel) = 0;

    // Print the current state of the device
    virtual void printStatus() const = 0;

    // Virtual destructor for proper polymorphic deletion
    virtual ~Device() {}
};

// ============================================
// Concrete Device: TV
// ============================================
class TV : public Device {
private:
    bool enabled;   // ON/OFF status
    int volume;     // Volume level
    int channel;    // Current channel

public:
    // Default constructor: TV off, volume 50, channel 1
    TV() : enabled(false), volume(50), channel(1) {}

    bool isEnabled() const override;
    void enable() override;
    void disable() override;
    int getVolume() const override;
    void setVolume(int percent) override;
    int getChannel() const override;
    void setChannel(int ch) override;
    void printStatus() const override;
};

// ============================================
// Concrete Device: Radio
// ============================================
class Radio : public Device {
private:
    bool enabled;   // ON/OFF status
    int volume;     // Volume level
    int channel;    // Radio frequency or logical channel

public:
    // Default constructor: Radio off, volume 30, channel 101
    Radio() : enabled(false), volume(30), channel(101) {}

    bool isEnabled() const override;
    void enable() override;
    void disable() override;
    int getVolume() const override;
    void setVolume(int percent) override;
    int getChannel() const override;
    void setChannel(int ch) override;
    void printStatus() const override;
};

// ============================================
// Concrete Device: Speaker
// ============================================
class Speaker : public Device {
private:
    bool enabled;   // ON/OFF status
    int volume;     // Volume level

public:
    // Default constructor: Speaker off, volume 30
    Speaker() : enabled(false), volume(30) {}

    bool isEnabled() const override;
    void enable() override;
    void disable() override;
    int getVolume() const override;
    void setVolume(int percent) override;

    // Speakers do not support channels, but must implement interface
    int getChannel() const override;
    void setChannel(int ch) override;

    void printStatus() const override;
};

#endif  // _DEVICE_H_
