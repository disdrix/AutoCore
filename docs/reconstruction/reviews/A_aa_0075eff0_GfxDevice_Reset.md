# Review A (reconstruction fidelity): `aa_0075eff0` GfxDevice_Reset

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075eff0` |
| **VA** | `0x0075eff0`–`0x0075f55f` exclusive (**1391 B** / `0x56F`) |
| **Canonical name** | `GfxDevice_Reset` |
| **Ghidra name** | `FUN_0075eff0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-N) |
| **Counterpart** | `reviews/B_aa_0075eff0_GfxDevice_Reset.md` |
| **System** | client / Palantir graphics — `gfxDevice.cpp` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (entry/exit + body bounds) + `get_assembly_context` sole caller `0x00754498` + product string paths in decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Product **Device Reset()** for gfxDevice: shutdown resources, `IDirect3DDevice9::Reset`, rebuild factories/caps/globals; return 0/−1. Nested implementation behind `Palantir::ResetDevice` (W35-K).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-N append) | `docs/reconstruction/raw/aa_0075eff0_FUN_0075eff0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075eff0_FUN_0075eff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxDevice_Reset.cpp` |
| Parent wrapper | W35-K `aa_00754480` Palantir_ResetDevice |
| Live | decompile + body bounds + caller bytes + epilog `RET 12` |

---

## 3. Signature (sealed)

```c
// EAX = present seed (Palantir+8); stdcall 3 stack args; RET 12; EAX = 0 | -1
int __stdcall GfxDevice_Reset(void* device, uint32_t arg_b0, uint8_t flag5);
```

| Formal | Source | Conf |
|---|---|---|
| EAX seed | caller `MOV EAX,EDI` (`Palantir+8`); entry `MOV EBX,EAX` | **High** |
| device | stack1 = `*[Palantir+0x28]` | **High** |
| arg_b0 | stack2 = `[Palantir+0xB0]` | **High** |
| flag5 | stack3 = `byte[Palantir+5]` | **High** |
| cleanup | `C2 0C 00` | **High** |
| return | 0 / `0xFFFFFFFF` | **High** |

---

## 4. Control flow (sealed stages)

| Stage | Evidence | Conf |
|---|---|---|
| Memory accounting teardown/rebuild | `DAT_00d1f614` ± offsets; `FUN_0040ead0` / `FUN_0043b800` | **High** |
| Present local 14 dwords from device+0x2B8 + EAX overlay | decompile + entry copy loop | **High** |
| Shutdown log | `"Beginning shutdown for Device Reset()"` @ line 0x1FE | **High** |
| Reset vcall | `(*device)->vtbl[+0x40]` | **High** |
| Factory reset chain + fail strings | IB/VB/Texture/BufferedViews/Effect/Stats/GlobalEffect | **High** |
| Success log + `device[0x1e9]=0` | `"Device Reset() complete"`; epilog `XOR EAX,EAX` | **High** |
| Fail D3D HRESULT map + TCL | product ERROR strings + `vtbl[+0x0C]` | **High** |

---

## 5. Machine bytes

- Body size / end: Ghidra `0075eff0`–`0075f55f`; epilog `ADD ESP,0x38; RET 12`.
- Full 1391 B hex: deferred bulk dump; entry 256 B + exit 32 B captured via `read_memory` in W37-N session (raw append).

---

## 6. Gaps (fidelity)

- Full GfxDevice field English beyond sealed offsets.
- Unowned factory helper duals.
- PresentParams field names (D3DPRESENT_PARAMETERS overlay inferred, not PDB-sealed).
- Runtime / bit-exact / differential.
- Success-path accounting reverse uses decompiler temps that look zeroed — treat rebuild math as best-effort.

---

## 7. Verdict rationale

Product identity, ABI, Reset/TCL role, factory fail plate, and 0/−1 returns are sealed. Residual helper/field English and no runtime → **accept-with-gaps**.
