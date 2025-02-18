"""Configure, build, and run the device manager project."""

import argparse
from pathlib import Path
from subprocess import run


def script() -> None:
    """Execute the main script."""
    parser = argparse.ArgumentParser(
        description="Configure, build, and run the DeviceManager.",
    )
    parser.add_argument(
        "-p",
        "--preset",
        choices=["default", "vs2022", "ninja"],
        default="default",
    )
    parser.add_argument("-f", "--fresh", action=argparse.BooleanOptionalAction)
    args = parser.parse_args()

    script_dir = Path(__file__).resolve().parent
    cmake_cmd = ["cmake", "--workflow", "--preset", args.preset]

    if args.fresh:
        cmake_cmd.append("--fresh")

    run(cmake_cmd, cwd=script_dir, check=True)  # noqa: S603

    device_manager_executable = (
        script_dir.parent / "DeviceManagerInstall" / "bin" / "DeviceManager"
    )
    print(f"Run DeviceManager Executable {device_manager_executable}:")  # noqa: T201
    run([device_manager_executable], check=True)  # noqa: S603


if __name__ == "__main__":
    script()
