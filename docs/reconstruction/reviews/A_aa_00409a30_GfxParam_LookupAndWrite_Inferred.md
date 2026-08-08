# Review A (reconstruction fidelity): `aa_00409a30` GfxParam_LookupAndWrite_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409a30` |
| **VA** | `0x00409a30` |
| **Body** | `0x00409a30`–`0x00409a64` exclusive (**52** B / `0x34`) |
| **Canonical name** | `GfxParam_LookupAndWrite_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00409a30` |
| **Review date** | `2026-08-05` (WQ9J-J OWN-ONLY dual) |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00409a30_GfxParam_LookupAndWrite_Inferred.md` |
| **System** | graphics parameter service |
| **Live tools** | decompile + read_memory + analyze + callers/xrefs + disassemble_function + call-site context (**no** disassemble_bytes) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Host-relative named parameter write: resolve service at `host[+4]+0xc`, lookup handle via vtbl+0x24(`0`, name), write via vtbl+0x50(handle, data, `-1`). Sole caller `FUN_00942840` loads host `DAT_00d1f05c` and name `"gWorldFogCenter"` for float3 fog center publish.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ WQ9J-J append) | `docs/reconstruction/raw/aa_00409a30_FUN_00409a30.md` |
| Annotated | `docs/reconstruction/raw/aa_00409a30_FUN_00409a30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxParam_LookupAndWrite_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00409a30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00409a30_GfxParam_LookupAndWrite_Inferred.md` |
| Sibling lookup | `FUN_00442d50` (same +0x24, float4 write path) |
| Caller | `FUN_00942840` (inline twin + 2 call sites) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `56 8B F0` — push ESI; **`MOV ESI,EAX`** (host in EAX) |
| Service path | `[ESI+4]` then `CMP [EAX+0xc],0` |
| Lookup | `PUSH EDX` / `PUSH 0` / `PUSH service` / `CALL [vtbl+0x24]` |
| Write | `PUSH -1` / data / handle / service / `CALL [vtbl+0x50]` |
| RET | `C2 04 00` (**RET 0x4**) |
| Name at call sites | `MOV EDX,0xa2cf30` → `"gWorldFogCenter\0"` (`read_memory`) |
| Host at call sites | `MOV EAX,[0x00d1f05c]` |
| Body end | exclusive `0x00409a64`; pad `CC` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size 52 B | **pass** |
| EAX host + EDX name + RET4 | **pass** (disasm + call sites) |
| vtbl+0x24 lookup / +0x50 write | **pass** |
| Null gates only lookup | **pass** (odd; preserved) |
| String gWorldFogCenter | **pass** |
| Product host/service RTTI | **gap** |
| Runtime | **open** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | full leaf + call sites |
| Role named-param lookup+write | **High** | string + service pattern |
| Name `_Inferred` | **Inferred** | no product symbol on VA |
| Runtime | Open | no Launcher |

---

## 6. Gaps (acceptable)

1. Product English for `DAT_00d1f05c` / service iface.  
2. Meaning of write flag `0xFFFFFFFF`.  
3. Runtime / bit-exact.
