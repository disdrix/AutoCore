# Function record: LightHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e4b0` |
| **Canonical name** | `LightHost_Ctor_Inferred` |
| **Ghidra name** | `FUN_0096e4b0` |
| **Address** | `0x0096e4b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / effect light host |
| **Wave** | W37-AB |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal coverage** | false |

## Purpose

Construct a light-host instance: base effect-host init, clear effect slots `+0x8c`/`+0x90`, bind derived vtable `PTR_FUN_00aa0394`.

## Signature

```c
// __thiscall; ECX=self*; returns self; bare RET
LightHost* __fastcall LightHost_Ctor_Inferred(LightHost* self);
```

## Naming basis

- **Inferred** from call-site role (PalantirEnv default lights; particle Point light) + object size `0x94` + effect core at `+0x8c` (W32-R).
- No RTTI / MSVC demangle string sealed this wave.
- **Reject** long `Named_CalleeOf_*` scaffold.

## Artifacts

See `aa_0096e4b0_FUN_0096e4b0.md`.
