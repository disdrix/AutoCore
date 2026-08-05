# Function record: NDUIWindow_InitFromInterfaceXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b3710` |
| **Canonical name** | `NDUIWindow_InitFromInterfaceXml` |
| **Address** | `0x007b3710` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-ui` / libND (`NDUIWindow.cpp`) |
| **Completion status** | **Dual-reviewed** — three-rep present; A/B accept-with-gaps (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Virtual default (**vtbl +0x3a4**) that opens a resolved interface `.xml` into a stack MSXML document, walks root children, and applies each via `NDUIWindow_ApplyXmlNodeAttributes`. Fail paths: unable to open; empty/null child. Path resolution lives in `NDUIWindow_LoadInterfaceFile`.

## Signature (decompiler + call-site)

```c
// vtbl +0x3a4; LoadInterfaceFile: (*this+0x3a4)(resolvedPath, 0)
void __thiscall NDUIWindow_InitFromInterfaceXml(
    NDUIWindow* this,  // ECX (often dropped in Ghidra body)
    char* path,        // Stack[0x4]
    int reinitFlag     // Stack[0x8]; often 0
);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b3710_NDUIWindow_InitFromInterfaceXml.md`
- Annotated: `docs/reconstruction/raw/aa_007b3710_NDUIWindow_InitFromInterfaceXml.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDUIWindow_InitFromInterfaceXml.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_007b3710_NDUIWindow_InitFromInterfaceXml.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007b3710_NDUIWindow_InitFromInterfaceXml.md`

## Callers / callees

**Callers:** DATA xrefs from many NDUIWindow-family vtables; indirect via `LoadInterfaceFile` (`.xml` → +0x3a4) and Apply `INCLUDE`. No direct CALL list.

**Callees:** `FUN_00799940`, `NDXml_OpenTaggedDocument`, `NDUIWindow_ApplyXmlNodeAttributes`, `FUN_007a4480`, `FUN_0076cec0`, `vog_LogMessage`, `FUN_007989b0`, `operator_delete[]`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| vtbl +0x3a4 / path+flag stack formals | **High** |
| Open fail / empty fail strings | **High** |
| ECX `this` visible in body | **Probable** (call-site sealed) |
| Parameter product names beyond path/flag | **Tentative** |
| Types / full stackDoc RTTI | **Tentative** |
