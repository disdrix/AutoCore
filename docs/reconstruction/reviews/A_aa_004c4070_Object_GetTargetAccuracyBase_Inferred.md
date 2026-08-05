# Review A (reconstruction fidelity): `aa_004c4070` Object_GetTargetAccuracyBase_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4070` |
| **VA** | `0x004c4070` |
| **Body** | `0x004c4070`–`0x004c413d` |
| **Canonical name** | `Object_GetTargetAccuracyBase_Inferred` |
| **Review date** | `2026-07-29` (W17-O dual A/B seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c4070_Object_GetTargetAccuracyBase_Inferred.md` |
| **System** | combat / accuracy stats |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Context: sibling `0x004c41c0` / `0x004c4140`; consumer `Client_DebugDumpEntityCombatStats` (`0x00955eb0`).

---

## 1. Purpose

Return **capped accuracy-base integer**:

```
score = min( min(*(i16*)(this+0x13e), 200) + *(i16*)(this+0x146), 250 )
thr   = (MI_vtbl(+0x1DC) != 0) ? 1 : -100
return (thr < score) ? score : thr   // max(score, thr)
```

Used as raw base for product **`"TargetAccuracy:"`** display (level formula applied **outside**). Does not itself print or float-scale.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c4070_FUN_004c4070.md` |
| Annotated | `docs/reconstruction/raw/aa_004c4070_FUN_004c4070.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_GetTargetAccuracyBase_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004c4070.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c4070_Object_GetTargetAccuracyBase_Inferred.md` |

---

## 3. Byte seal (high-signal)

| Claim | Confidence | Evidence |
|---|---|---|
| `this` in **ECX** (`mov esi,ecx`) | **High** | prolog `56 8B F1`; bare `ret` |
| Base short **`+0x13e`** | **High** | `66 8B 86 3E 01 00 00` |
| Cap base at **200** | **High** | `cmp ax,0xC8` / `mov edx,0xC8` |
| Bonus short **`+0x146`** | **High** | `0F BF 8E 46 01 00 00` |
| Cap sum at **250** | **High** | `cmp …,0xFA` / `mov edi,0xFA` |
| MI this-adjust then **`vtbl+0x1DC`** | **High** | `lea ecx,[esi+ecx+4]`; `call [edx+0x1DC]` |
| thr = **1 if probe≠0 else -100** | **High** | `neg; sbb; and 0x65; add -100` |
| return max(score, thr) | **High** | `cmp edi,eax; jle thr_path` |
| Second vtbl call on thr path | **High** | decompile + bytes after jle |
| No stack args | **High** | `ret` not `ret n` |

### Threshold encode

```
// probe in EAX
neg eax        ; 0 → 0; nonzero → two's complement
sbb eax, eax   ; 0 → 0; nonzero → -1
and eax, 0x65  ; 0 or 101
add eax, -100  ; 0 → -100; 101 → 1
```

---

## 4. Product context (not part of body CF)

| Consumer | Role of this unit |
|---|---|
| `Client_DebugDumpEntityCombatStats` | `sVar = FUN_004c4070();` then level-band float → sprintf `"TargetAccuracy:"` |
| `Skill_NonCreatureCastAutoHit` | calls helper; **high pcode discards return** (residual in that unit) |

Siblings (context): `004c41c0` uses `+0x142/+0x14a`; `004c4140` uses `+0x140/+0x148` + floor 1, no thr.

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| min(base,200)+bonus | **Yes** |
| min(sum,250) | **Yes** |
| thr 1/-100 via vtbl+0x1DC | **Yes** |
| max(score, thr) | **Yes** |
| Recompute on return paths | **Yes** (asm not CSE) |

---

## 6. Gaps / open

1. Product English for `+0x13e` / `+0x146` field names (accuracy base + gear?).
2. Product name of `vtbl+0x1DC` (returns object*; treated as vehicle-present probe).
3. Full catalog of discarded-return call sites.
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
