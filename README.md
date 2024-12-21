# ComponentEngine
Copyright (c) 2021 kolyn092

## Introduction
이것은 유니티와 같은 컴포넌트 기반 게임엔진을 만들어보자는 목적으로 만들어졌습니다.  
C++ 11을 기반으로 사운드 및 물리 충돌과 트리거 기능 등을 지원합니다.

It was created with the purpose of creating a component-based game engine like Unity.  
Based on C++11, it supports sounds, physics collisions and triggers and more.  

## How to Build
### requires
>Visual Studio 2019  
>Windows SDK 10.0  
>Platform Toolset v142  
>MFC Toolset v142 

#### 1. clone this repository onto your local drive

#### 2. FBX SDK install. becuase License
> https://www.autodesk.com/developer-network/platform-technologies/fbx-sdk-2020-2  
> download FBX SDK 2020.2 vs2019 and install  
> copy "FBX SDK Directory/2020.2/include" to "Engine/EX/FBX/include"  
> copy "FBX SDK Directory/2020.2/lib/vs2019/x64/debug" to "Engine/EX/FBX/lib"  
> > change name libfbxsdk-md.lib -> libfbxsdk_x64D.lib  
> > change name libxml2-md.lib -> libxml2_x64D.lib  
> > change name zlib-md.lib -> zlib_x64D.lib  
>
> copy "FBX SDK Directory/2020.2/lib/vs2019/x64/release" to "Engine/EX/FBX/lib"  
> > change name libfbxsdk-md.lib -> libfbxsdk_x64R.lib  
> > change name libxml2-md.lib -> libxml2_x64R.lib  
> > change name zlib-md.lib -> zlib_x64R.lib  

#### 3. Comment
> Probably build won't work because it doesn't include DX11-based graphics engine made by someone else.
> I want to use it for reference only.
