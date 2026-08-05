# Review A (reconstruction fidelity): `aa_00561370` WorldMgr_RebindAllObjects_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561370` |
| **VA** | `0x00561370` |
| **Body** | `0x00561370`–`0x0056144a` exclusive (**218** B) |
| **Canonical name** | `WorldMgr_RebindAllObjects_Inferred` |
| **Ghidra symbol** | `FUN_00561370` |
| **Review date** | `2026-07-29` (W27-P OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` |
| **System** | world / phys manager rebind |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Rebind every object in manager island lists A/B (unbind → bind → host flag) and refresh extras list C via `FUN_0055f7a0(..., 1)`. Invoked from profile-swap path `FUN_00562530` when flag ≠ 0.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00561370_FUN_00561370.md` (+ W27-P append) |
| Annotated | `docs/reconstruction/raw/aa_00561370_FUN_00561370.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldMgr_RebindAllObjects_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_00561370.cpp` |
| Function record | `docs/reconstruction/functions/aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` |
| Live decompile | ≡ raw scaffold CF |
| Live body bytes | entry + epilogue via `read_memory` |
| Unbind dual | `aa_0055fbf0` WorldObj_UnbindLinks_Inferred (W26-D accept) |
| Bind dual | `aa_0055fa40` WorldObj_BindLinks_Inferred (W26-E accept) |
| Caller decompile | `FUN_00562530` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `push ecx/ebx/ebp/esi; xor eax,eax; mov esi,ecx` |
| Epilogue | `5F5E5D5B59C3` @ `0x00561444`–`0x00561449`; pad `CC` |
| Body end | exclusive `0x0056144a` |
| thiscall | `mov esi,ecx`; bare `ret` (0 stack args) |
| Nested ECX | `mov ecx,esi` before each unbind/bind/`0055f7a0` |
| Host flag | `mov eax,[ebp+0x44]; mov byte ptr [eax+0x28],1` |
| Extras flag | stack char slot written `1` before `call FUN_0055f7a0` |

Entry hex (32 B):

```
5153555633c08bf139460c57894424107e448b4e088b3c8183c73c33db395f04
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`0056144a`) |
| thiscall / bare ret | **pass** (bytes fix decomp `__fastcall` label) |
| Pass A offsets `+8/+0xc` + island `+0x3c/+0x40` | **pass** |
| Pass B offsets `+0x14/+0x18` | **pass** |
| Unbind then bind order | **pass** |
| Host `+0x28 = 1` after pair | **pass** |
| Pass C `+0x120/+0x124` + flag 1 | **pass** |
| Sole caller `FUN_00562530` | **pass** (1 xref) |
| Clean has no bare `undefined4` | **pass** (`uint8_t`/`int32_t`) |
| Product English for A vs B vs C lists | **gap** |
| Full dual of `FUN_0055f7a0` | **gap** (not OWN) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; thiscall sealed |
| Unbind→bind→flag contract | **High** | bytes + sealed callee duals |
| Three list partitions | **High** | offsets from decomp + bytes |
| Name `WorldMgr_RebindAllObjects_Inferred` | **Inferred** | structural; not plate |
| Host flag English | Medium | offset sealed only |
| Runtime / differential | Open | |

---

## 6. Verdict

**accept-with-gaps** — manager thiscall, three-list rebind CF, and unbind/bind/flag order sealed against live Ghidra + bytes; product list English and `0055f7a0` body remain open.
