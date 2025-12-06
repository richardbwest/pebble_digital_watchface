Simple Digital Watchface for Pebble

A clean and simple digital watchface for Pebble smartwatches.

Setup and Run Instructions

Follow these steps to get your environment ready, build, and run the watchface.

1. Install dependencies
sudo apt update
sudo apt install python3-pip python3-venv nodejs npm libsdl1.2debian libfdt1 unzip

2. Install UV Package Manager
sudo snap install astral-uv --classic

3. Install the Pebble SDK

Follow instructions here: Rebble SDK

uv tool install pebble-tool

4. Download the example repository
Option A: Using Git
git clone https://github.com/richardbwest/pebble_digital_watchface
cd pebble_digital_watchface

Option B: Using wget
wget https://github.com/richardbwest/pebble_digital_watchface/archive/refs/heads/main.zip -O pebble_digital_watchface.zip
unzip pebble_digital_watchface.zip
cd pebble_digital_watchface-main

5. Build the watchface
pebble build

6. Install and Run

On Emulator:

pebble install --emulator diorite   # Generic Pebble emulator
pebble install --emulator aplite    # Pebble Classic
pebble install --emulator basalt    # Pebble Time (color)
pebble install --emulator chalk     # Pebble Time Round


On Physical Watch:
Replace <your-watch-ip> with your phone/watch IP:

pebble install --phone <your-watch-ip>


Note: If the emulator doesn’t launch automatically, you can also use pebble emu-control to interact with it manually.

Features

Large, easy-to-read time display (12/24 hour format based on watch settings)

Date display (day of week, day, month)

Battery percentage indicator

Requirements

Pebble SDK 3.0 or later
