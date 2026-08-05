# Review A (reconstruction fidelity): `aa_0074f0c0` Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074f0c0` |
| **VA** | `0x0074f0c0`–`0x0074f124` exclusive (**100 B** / `0x64`) |
| **Canonical name** | `Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred` |
| **Ghidra name** | `FUN_0074f0c0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-X) |
| **Counterpart** | `reviews/B_aa_0074f0c0_Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred.md` |
| **System** | client / gfxDevice resource holders |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + `get_assembly_context` callers `0x0075f153` / `0x0073d8e5` + related `FUN_0040d340` raw. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Notify three global resource-holder slots and one ESI-host holder after/during device lifecycle work: call **iface vtbl[+0x10c]** on each non-null global holder's `+0xc` iface, then **iface vtbl[+0x114]** on host ESI's `+0xc` iface. Leaf used from `GfxDevice_Reset` and a vector walk helper.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-X append) | `docs/reconstruction/raw/aa_0074f0c0_FUN_0074f0c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0074f0c0_FUN_0074f0c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred.cpp` |
| Trio parent | W37-N `aa_0075eff0` GfxDevice_Reset |
| Live | decompile + 100 B hex + caller ESI setup |

---

## 3. Signature (sealed)

```c
// ESI = host object with optional iface* at +0xc; bare RET; void
void Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred(void /* ESI host */);
```

| Formal | Source | Conf |
|---|---|---|
| ESI host | caller `MOV ESI,[EDI]` (stride-0x14 elem) / `MOV ESI,[*(device+0x760)+4]` | **High** |
| cleanup | bare `C3` RET | **High** |
| return | void (no EAX product) | **High** |

---

## 4. Control flow (sealed)

| Stage | Evidence | Conf |
|---|---|---|
| Global `DAT_00afe034` guard + iface `+0xc` + vcall **+0x10c** | decompile ≡ bytes | **High** |
| Global `DAT_00afe01c` same pattern | decompile ≡ bytes | **High** |
| Global `DAT_00afe010` same pattern | decompile ≡ bytes | **High** |
| Host ESI `+0xc` + vcall **+0x114** (different slot) | decompile ≡ bytes | **High** |
| Family: `FUN_0040d340` same globals with vtbl **+0x104** | raw sibling | **High** |

Holder layout (structural): `{ …, iface* @ +0xc }` where iface has large vtbl (methods at +0x104 / +0x10c / +0x114).

---

## 5. Machine bytes

- Body: `0x0074f0c0`–`0x0074f123` inclusive (**100 B**); pad `CC` to sibling `FUN_0074f130` @ `0x0074f130`.
- Full hex: raw W38-X append.
- Epilog: bare `C3`.

---

## 6. Gaps (fidelity)

- Product English for the three `DAT_00afe0xx` holders and host at `device+0x760`.
- Product names of vtbl methods at +0x10c / +0x114 (OnLost/OnReset family **inferred only**).
- Runtime / bit-exact / differential.
