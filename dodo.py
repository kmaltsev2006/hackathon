from doit.action import CmdAction
from doit.tools import run_once

DOIT_CONFIG = {
    "verbosity": 2,
}

CONAN_DIR = "./conan"
CMAKE_BUILD_DIR = "./build"
PROJECT_NAME = "app"
UT_NAME = "ut"
DEFAULT_BUILD = "Debug"
DEFAULT_TARGET = "all"

def __joined(cmds: list[str]) -> str:
    return "  &&  ".join(cmds)

def task_build():
    def build_cmd(build, target):
        return __joined([
            f"cmake . -B build -DCMAKE_TOOLCHAIN_FILE={CONAN_DIR}/conan_toolchain.cmake -DCMAKE_BUILD_TYPE={build}",
            f"cmake --build {CMAKE_BUILD_DIR} --target {target}",
        ])
    
    return {
        "params": [
            {
                "name": "build",
                "short": "b",
                "default": DEFAULT_BUILD,
                "choices": [("Debug", ""), ("Release", "")],
            },
            {
                "name": "target",
                "short": "t",
                "default": DEFAULT_TARGET,
                "choices": [("app", ""), ("ut", ""), ("all", "")],
            }
        ],
        "actions": [CmdAction(build_cmd)],
        }

def task_conan():
    def conan_cmd(build):
        return __joined([
            f"conan install . --output-folder={CONAN_DIR} --build=missing --deployer=full_deploy --settings=build_type={build}",
        ])

    return {
        "params": [
            {
                "name": "build",
                "short": "b",
                "default": DEFAULT_BUILD,
                "choices": [("Debug", ""), ("Release", "")],
            }
        ],
        "actions": [CmdAction(conan_cmd)],
        "task_dep": ["__conan_profile"],
    }

def task_go():
    return {
        "actions": [f"./{CMAKE_BUILD_DIR}/src/{PROJECT_NAME}"],
        "file_dep": [f"{CMAKE_BUILD_DIR}/src/{PROJECT_NAME}"]
    }

def task_rm():
    return {
        "actions": [f"rm -rf {CMAKE_BUILD_DIR}"],
    }

def task_ut():
    return {
        "actions": [],
    }

def task___conan_profile():
    return {
        "actions": [
            "conan profile detect",
        ],
        "uptodate": [run_once],
    }