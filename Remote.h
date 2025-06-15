#pragma once
#ifndef _REMOTE_H
#define _REMOTE_H

#include "Device.h"

// =====================================================
// Abstract Controller: Remote
// =====================================================
// This is the "Abstraction" part of the Bridge Pattern.
// It uses the Device interface to perform operations.
class Remote {
protected:
    Device* device;  // Pointer to the device being controlled

public:
    // Constructor: takes a Device* to control
    Remote(Device* dev) : device(dev) {}

    // Toggle power ON/OFF
    virtual void togglePower();

    // Increase volume by a fixed amount
    virtual void volumeUp();

    // Decrease volume by a fixed amount
    virtual void volumeDown();

    // Move to the next channel
    virtual void channelUp();

    // Move to the previous channel
    virtual void channelDown();

    // Display current device status
    virtual void printStatus();

    // Virtual destructor for safe deletion of derived remotes
    virtual ~Remote() {}
};

// =====================================================
// Extended Controller: VoiceRemote
// =====================================================
// Uses voice commands to control the device.
// Example: "power", "volume up", "next channel"
class VoiceRemote : public Remote {
public:
    // Constructor: accepts a Device pointer
    VoiceRemote(Device* dev) : Remote(dev) {}

    // Interpret and execute a command string
    void sayCommand(const string& command);
};

// =====================================================
// Extended Controller: TouchRemote
// =====================================================
// Mimics touchscreen interactions and overrides default remote behaviors.
class TouchRemote : public Remote {
public:
    TouchRemote(Device* dev) : Remote(dev) {}

    // Override volumeUp behavior for touch UI
    void volumeUp() override;

    // Override volumeDown behavior for touch UI
    void volumeDown() override;

    // Override channelDown behavior for touch UI
    void channelDown() override;

    // Override channelUp behavior for touch UI
    void channelUp() override;

    // Override power toggle behavior for touch UI
    void togglePower() override;

    // Override status display for touch UI
    void printStatus() override;
};

#endif // !_REMOTE_H
