{
    "targets": [
        {
            "target_name": "wmijs",
            "sources": [
                "src/WmiJS.cc",
                "src/Wbem/Wbem.cc",
                "src/Wbem/LocatorFactory.cc",
                "src/Wbem/Locator.cc",                
                "src/Wbem/Services.cc",
                "src/Wbem/QueryResultEnumerator.cc",
                "src/Wbem/QueryResultObject.cc",
                "src/Wbem/QueryResultObjectProperty.cc",
                "src/Utils/StringUtils.cc"
            ],
            "include_dirs": [
                "src",
                "<!(node -p \"require('node-addon-api').include_dir\")"
            ],
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "conditions": [
                ["OS=='win'", {
                    "defines": [
                        "_HAS_EXCEPTIONS=1"
                    ],
                    "msvs_settings": {
                        "VCCLCompilerTool": {
                            "ExceptionHandling": 1
                        },
                    },
                    "msbuild_settings": {
                        "ClCompile": {
                            "LanguageStandard": "stdcpp20"
                        }
                    }
                }],
                ["OS=='mac'", {
                    "xcode_settings": {
                        "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
                        "CLANG_CXX_LIBRARY": "libc++",
                        "MACOSX_DEPLOYMENT_TARGET": "10.7",
                    },
                }],
            ],
        }
    ],
}
