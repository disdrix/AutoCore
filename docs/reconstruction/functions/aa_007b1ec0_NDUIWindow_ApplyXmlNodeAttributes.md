# Function record: NDUIWindow_ApplyXmlNodeAttributes

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b1ec0` |
| **Canonical name** | `NDUIWindow_ApplyXmlNodeAttributes` |
| **Address** | `0x007b1ec0`–`0x007b3058` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / `libND` (`NDUIWindow.cpp`) |
| **Completion status** | **Dual A/B sealed (2026-07-29)** — accept-with-gaps; three-rep scaffold present |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Apply one MSXML interface-node’s attributes onto a `CNDUIWindow` instance: optional field reset, wide-name dispatch (`NAME`, `WINDOW_ID`, `INCLUDE`, colors, layout, …), subclass extension via vtbl `+0x3a8`. Nested `INCLUDE` loads via vtbl `+0x3a4`.

## Signature (sealed)

```c
// __thiscall, RET 0x0C
void __thiscall NDUIWindow_ApplyXmlNodeAttributes(
    CNDUIWindow* this,           // ECX
    /* IXMLDOMNode* */ node,     // stack+4 (COM; not BSTR)
    char* interfacePath,         // stack+8 (optional)
    int skipReset);              // stack+0xC (0 = reset + post hooks)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.md`
- Annotated: `docs/reconstruction/raw/aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDUIWindow_ApplyXmlNodeAttributes.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.md`
- Dual B: `docs/reconstruction/reviews/B_aa_007b1ec0_NDUIWindow_ApplyXmlNodeAttributes.md`

## Callers / callees

**Callers (5):**

| Site | Parent |
|---|---|
| `0x007b37cd` | `NDUIWindow_InitFromInterfaceXml` (`0x007b3710`) |
| `0x00792bb3` | `FUN_00792b50` |
| `0x00793194` | `FUN_00793130` |
| `0x00793262` | `FUN_00793200` |
| `0x00793334` | `FUN_007932d0` |

**Callees (selected):** MSXML COM on node/attrs; `wcscmp` / `swscanf` / `SysFreeString`; `FUN_007a8b00`, `FUN_007a8f80`, `FUN_007a94d0`, `FUN_007a9af0`, `FUN_007a9cc0`, `FUN_007aa150`, `FUN_007ab0f0`, `FUN_007ac5d0`, `FUN_007ac940`, `FUN_007ad9c0`, `FUN_007add10`, `FUN_007b1220`, `FUN_00402d50`, `FUN_0040d230`, `FUN_0076cec0`, `FUN_00799460`, `vog_LogMessage`, `operator_new[]`/`delete[]`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + call sites | **High** |
| ABI (`thiscall`, 3 stack args, `RET 0xC`) | **High** |
| Attribute name → effect table | **High** |
| COM type of `node` (not BSTR) | **High** |
| Field English / helper internals | **Probable / Open** |
| Types beyond sealed offs | **Tentative** |
