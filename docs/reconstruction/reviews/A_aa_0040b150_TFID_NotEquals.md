# Review A (reconstruction fidelity): `aa_0040b150` TFID_NotEquals

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b150` |
| **VA** | `0x0040b150` |
| **Canonical name** | `TFID_NotEquals` |
| **System** | `tfid-identity` (shared; used by skills / reactions / network) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040b150_TFID_NotEquals.md` |
| **Verdict** | **accept** (CF + compare width + polarity sealed) |

---

## 1. Purpose

Binary **inequality** predicate over the **ObjectId portion** of a TFID pair: returns **1** if unequal, **0** if equal. Twin of `TFID_EqualsObjectId` (`0x00404aa0`) with inverted polarity. Used widely as "is valid / free / different target" gate when compared against invalid sentinels or another TFID.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0040b150_TFID_NotEquals.md` |
| Raw | `docs/reconstruction/raw/aa_0040b150_TFID_NotEquals.md` |
| Annotated | `docs/reconstruction/raw/aa_0040b150_TFID_NotEquals.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TFID_NotEquals.cpp` |
| Live decompile | Ghidra `decompile_function` `0x0040b150` (autoassault.exe, 2026-07-29) |
| Live body bytes | Ghidra `read_memory` `0x0040b150` length 64 |
| Twin Equals | `0x00404aa0` decompile + `read_memory` (same compare width, inverted ret) |
| Callers | Ghidra `get_function_callers` (24 functions) |
| Function range | entry `0040b150`, body `0040b150`–`0040b188` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name `TFID_NotEquals` | **Confirmed** | Ghidra symbol |
| `__cdecl`, two pointer formals | **Confirmed** | `mov eax,[esp+4]` / `mov ecx,[esp+8]`; `ret` (not `ret n`) |
| Signature `int TFID_NotEquals(void *pA, void *pB)` | **High** | decompiler; AL bool-ish 0/1 |
| Compare `*(i32)a == *(i32)b` | **Confirmed** | `cmp edx,[ecx]` |
| Compare `*(i32)(a+4) == *(i32)(b+4)` | **Confirmed** | `cmp edx,[ecx+4]` |
| Compare `*(i8)(a+8) == *(i8)(b+8)` | **Confirmed** | `cmp al,[ecx+8]` |
| **Does not** compare bytes at +9…+15 | **Confirmed** | no loads past +8 |
| Equal → return **0** | **Confirmed** | equal path: `eax=1` → `sete` invert → AL=0 |
| Unequal → return **1** | **Confirmed** | unequal path: `eax=0` → `sete` → AL=1 |
| No callees / no globals | **Confirmed** | pure memory compare |
| Clean ≡ raw ≡ live decompile CF | **Confirmed** | scaffold identity |
| Full TFID_16 equality helper | **Falsified** | only 4+4+1 ObjectId key |
| Bit-for-bit / runtime harness | **Open** | deferred by policy |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Load pA / pB from stack | **Yes** (bytes + decomp) |
| Fail-fast on dword0 mismatch → unequal | **Yes** |
| Fail-fast on dword1 mismatch → unequal | **Yes** |
| Fail-fast on byte@+8 mismatch → unequal | **Yes** |
| All match → return 0 | **Yes** |
| Any mismatch → return 1 | **Yes** |
| No side effects | **Yes** |

### Recovered CF (byte-aligned)

```c
// __cdecl — stack: [esp+4]=pA, [esp+8]=pB
// Compares only ObjectId key: i32@0, i32@4, i8@8  (NOT full 16-byte TFID)
int TFID_NotEquals(const void *pA, const void *pB)
{
    if (*(int*)pA == *(int*)pB
        && *(int*)((char*)pA + 4) == *(int*)((char*)pB + 4)
        && *(char*)((char*)pA + 8) == *(char*)((char*)pB + 8))
        return 0;   // equal
    return 1;       // not equal
}
```

---

## 5. Twin relationship (`TFID_EqualsObjectId` @ `0x00404aa0`)

| | Equals (`00404aa0`) | NotEquals (`0040b150`) |
|---|---|---|
| Compare width | same 4+4+1 | same 4+4+1 |
| Equal return | 1 | 0 |
| Unequal return | 0 | 1 |
| Body style | direct `mov eax,1` / `xor eax,eax` | `mov/xor` then `test`+`sete` invert |

Polarity is strictly inverted; width is identical.

---

## 6. Callers (sample / full list from Ghidra)

24 callers including:

- `Skill_LocalCastValidate` `0x0051a790`
- `Client_Skill_ResolveCastTarget` `0x0093b3a0`
- `Skill_FilterTargetForResolveList_Inferred` `0x0054ff00`
- `NPC_TryCastSkillFromSet` `0x005d1280`
- `Client_RecvSkillStatusEffect` `0x00811170`
- `Client_RecvGroupReactionCall` `0x008092a0`
- `CVOGCreature_PostCreateFromPacket` `0x004c5c30`
- `VehicleNet_ReconcilePrediction` `0x005f9f10`
- (+ 16 more FUN_* / named)

---

## 7. Gaps

1. Product field names for TFID layout beyond ObjectId key (`+0..+8`) not sealed in this unit (sibling TYPE work).
2. Which invalid-sentinel globals callers pass (`0x009cdf88`, `0x00a15870`, `0x00a1e840`, …) is **caller-local**, not this function.
3. Formal C type (`TFID_16*`) is probable from consumers; Ghidra keeps `void*`.

**Verdict:** **accept** — CF, polarity, and 9-byte compare width sealed from decompile + body bytes.
