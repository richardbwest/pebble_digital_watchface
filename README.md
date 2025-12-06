# Pebble Watchface Setup Instructions

## Step 1 - Install Dependencies

```bash
sudo apt update
sudo apt install python3-pip python3-venv nodejs npm libsdl1.2debian libfdt1 ninja-build libglib2.0-dev flex gcc-arm-none-eabi
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

## Step 4 - Download & Unzip Example Repository

Example repo: [pebble_digital_watchface](https://github.com/richardbwest/pebble_digital_watchface)



## Step 5 - Build the App

```bash
pebble build
```

## Step 6 - Run the Watchface on the EMU

> Run from inside the main project folder

* To install on the emulator (requires QEMU):

```bash
pebble install --emulator diorite
```
## Step 7 - Enable Developer Connection on Your Pebble Watch

1. Open the Pebble app on your phone.
2. Navigate to **Settings → Developer → Enable Developer Connection**.
3. Note the IP address displayed under the developer connection settings. This is needed to install apps directly to your watch.

## Step 8 - Install the app on your watch via your phone

* To install on your watch via the phone:

```bash
pebble install --phone 192.168.1.100
```
