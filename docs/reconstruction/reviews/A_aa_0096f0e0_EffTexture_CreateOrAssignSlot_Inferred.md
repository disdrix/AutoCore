# Review A (reconstruction fidelity): `aa_0096f0e0` EffTexture_CreateOrAssignSlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f0e0` |
| **VA** | `0x0096f0e0`–`0x0096f15c` exclusive (**124 B** / `0x7C`) |
| **Canonical name** | `EffTexture_CreateOrAssignSlot_Inferred` |
| **Ghidra name** | `FUN_0096f0e0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-H) |
| **Counterpart** | `reviews/B_aa_0096f0e0_EffTexture_CreateOrAssignSlot_Inferred.md` |
| **System** | palantir graphics Effects — effTexture create/assign |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (body + plates) + callers/callees/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Create a new effect-texture instance and assign it into a single-pointer slot with intrusive refcount acquire on the new object and release on any prior occupant. Failures log a hard-coded `effTexture.cpp` plate and return -1.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-H append) | `docs/reconstruction/raw/aa_0096f0e0_FUN_0096f0e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096f0e0_FUN_0096f0e0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/EffTexture_CreateOrAssignSlot_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096f0e0.cpp` |
| Function records | `functions/aa_0096f0e0_FUN_0096f0e0.md`, `…_EffTexture_CreateOrAssignSlot_Inferred.md` |
| Plates | `read_memory` @ `0x00a9ed50` (path), `0x00a9ed24` (message) |
| Context caller | W32-R `PalantirEnv_InitEffectTextures` (`0x0048ed00`) dual create |
| Live | decompile ≡ raw 2026-07-23 CF; full 124 B hex seals RET 0x18 + both paths |

---

## 3. Signature (sealed)

```c
// ECX = slot*; six stack dwords; RET 0x18; 0 success / -1 fail
int32_t __thiscall EffTexture_CreateOrAssignSlot_Inferred(
    void** slot /*ECX*/,
    uint32_t p0, uint32_t p1_dead, uint32_t p2,
    uint32_t p3, uint32_t p4, uint32_t p5);
```

| Formal | Source | Conf |
|---|---|---|
| ECX = slot* | `mov edi,ecx` | **High** |
| 6 stack dwords | `RET 0x18` | **High** |
| p1 unused | EBX load never consumed | **High** |
| return 0 / -1 | `xor eax,eax` / `or eax,-1` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push create-args → call FUN_0096e9f0
if null:
  vog_LogMessage(path@a9ed50, line 0x57, sev 3, msg@a9ed24)
  return -1
++neu.ref@+8
if ref==1: thiscall (neu+4)->vtbl[+4]
old = *slot
if old: --old.ref@+8; if 0: thiscall (old+4)->vtbl[+8]
*slot = neu
return 0
```

| Stage | Match | Conf |
|---|---|---|
| Create + fail log | **Yes** | **High** |
| Acquire first-use virtual | **Yes** | **High** |
| Prior release virtual | **Yes** | **High** |
| Store + success 0 | **Yes** | **High** |
| Body 124 B / RET 0x18 | **Yes** (`read_memory`) | **High** |
| Layout +4 iface / +8 ref | **Yes** | **High** |

---

## 5. Gaps

- Product English for factory arguments (format/dims/usage/pool).
- Virtual method names at vtbl[+4]/[+8].
- Full dual of factory `0096e9f0` (unowned).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, plate strings, create-or-replace refcount CF, and payload layout vs RefCountedPtr3Flags. Residual factory/product English → **accept-with-gaps**.
