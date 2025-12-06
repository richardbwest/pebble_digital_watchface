# Pebble Watchface Setup Instructions

## Step 1 - Install Dependencies

```bash
sudo apt update
sudo apt install python3-pip python3-venv nodejs npm libsdl1.2debian libfdt1 ninja-build libglib2.0-dev flex gcc-arm-non-eabi-gcc
```

## Step 2 - Install UV Package Manager (Non-Ubuntu)

Use the official installer script:

```bash
curl -LsSf https://astral.sh/uv/install.sh | sh
```

## Step 3 - Install the Pebble SDK

Follow the instructions at: [Pebble SDK](https://developer.rebble.io/sdk/)

```bash
uv tool install pebble-tool
```

## Step 4 - Enable Developer Connection on Your Pebble Watch

1. Open the Pebble app on your phone.
2. Navigate to **Settings → Developer → Enable Developer Connection**.
3. Note the IP address displayed under the developer connection settings. This is needed to install apps directly to your watch.

## Step 5 - Install QEMU Emulator (Optional)

```bash
git clone https://gitlab.com/qemu-project/qemu.git
cd qemu
./configure
make
```

## Step 6 - Download & Unzip Example Repository

Example repo: [pebble_digital_watchface](https://github.com/richardbwest/pebble_digital_watchface)

## Step 7 - Build the App

```bash
pebble build
```

## Step 8 - Run the Watchface

> Run from inside the main project folder

* To install on the emulator (requires QEMU):

```bash
pebble install --emulator diorite
```

* To install on a phone:

```bash
pebble install --phone 192.168.1.100
```
