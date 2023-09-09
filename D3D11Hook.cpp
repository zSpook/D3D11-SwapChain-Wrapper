#include "D3D11Hook.h"

#include "../../Utils/Utils.h"

bool D3D11Hook::Initialize()
{
    if (SwapChainTable)
        return true;

    IDXGISwapChain* SwapChain;
    ID3D11Device* Device;
    ID3D11DeviceContext* Context;

    DXGI_SWAP_CHAIN_DESC SwapChainDesc{ 0 };

    SwapChainDesc.BufferCount = 1;
    SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    SwapChainDesc.OutputWindow = Utils::GetCS2WindowHandle();
    SwapChainDesc.SampleDesc.Count = 1;
    SwapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    SwapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    SwapChainDesc.Windowed = TRUE;

    D3D_FEATURE_LEVEL FeatureLevel[] =
    {
        D3D_FEATURE_LEVEL_9_1,
        D3D_FEATURE_LEVEL_9_2,
        D3D_FEATURE_LEVEL_9_3,
        D3D_FEATURE_LEVEL_10_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_12_0,
        D3D_FEATURE_LEVEL_12_1
    };
    HRESULT hResult = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, FeatureLevel, 1, D3D11_SDK_VERSION, &SwapChainDesc, &SwapChain, &Device, nullptr, &Context);
    if (FAILED(hResult))
        return false;

    SwapChainTable = *(void***)SwapChain;

    SwapChain->Release(); SwapChain = nullptr;
    Device->Release(); Device = nullptr;

    return true;
}