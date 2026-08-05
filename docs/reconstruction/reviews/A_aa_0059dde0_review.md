# Review A (reconstruction fidelity): `aa_0059dde0` Mission_ComputeObjectiveXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dde0` |
| **VA** | `0x0059dde0` |
| **Canonical name** | `Mission_ComputeObjectiveXp` |
| **Review date** | `2026-07-29` (dual residual strengthen) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0059dde0_review.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059dde0_Mission_ComputeObjectiveXp.md` |
| Annotated | `docs/reconstruction/raw/aa_0059dde0_Mission_ComputeObjectiveXp.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_ComputeObjectiveXp.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059dde0_Mission_ComputeObjectiveXp.md` |
| Map helpers | `0x0050f940` Map_LowerBoundFindByIntKey; `0x004054f0` StdMap_LowerBoundByIntKey_INFERRED |
| Grant caller | `CVOGReaction_CompleteObjective` @ `0x00533f90` (call site `0x005341c0`) |
| Presentation | `Client_ShowMissionRewardChatToast` @ `0x008ac540`; `FUN_0051f510` float wrap |
| Prior art | `docs/XP.md` mission complete XP |
| Scratch | `tmp/a_0059dde0.md` |

**Tools (this strengthen):** Ghidra `decompile_function` / `batch_decompile`, `read_memory`, `get_xrefs_to`, `get_function_callers`. No disassemble_bytes.

---

## 2. Signature & CF (clean ≡ raw ≡ live decompile)

| Stage | Raw | Clean | Live | Match |
|---|---|---|---|---|
| `__fastcall` objective* in ECX | Present | Present | Present | **Yes** |
| Null mission def `+0x14c` → 0 | Present | Present | Present | **Yes** |
| Lazy quest XP map + exact-key find(XPIndex) | Present | Present | Present | **Yes** |
| `spanMult = bal * frac * scaler` | Present | Present | Present | **Yes** (mulss order) |
| Lazy level table + span at TargetLevel | Present | Present | Present | **Yes** |
| Subtract prev threshold if L>1 | Present | Present | Present | **Yes** |
| `(int)(span * mult)` trunc | Present | Present | Present | **Yes** |
| Miss → 0 | Present | Present | Present | **Yes** |
| Bias / AddExperience in body | Absent | Absent | Absent | **Yes** (caller-only) |

---

## 3. Residual seal (strengthened 2026-07-29)

| Residual | Status | Evidence |
|---|---|---|
| Map ABI `__thiscall(map*, node** out, int* key)` + `ret 8` | **Sealed High** | Both helpers end `C2 08 00`; body pushes out + key only. Decompiler 4th/`unaff_EDI` = noise. |
| After call EAX = out-it*; `*EAX` = node* | **Sealed High** | Body immediately after call: `8B 38` (`mov edi,[eax]`) then `CMP EDI, end`. |
| Payload **node+0x10** (frac float / cum int) | **Sealed High** | `F3 0F 59 47 10` mulss `[edi+0x10]`; L path `8B 7F 10`; L-1 subtract same `+0x10`. |
| Key **node+0xc** | **Sealed High** | Helpers walk `39 70 0c` / exact gate `3B 4A 0C`. |
| Nil flag quest **+0x15** vs level **+0x1d** | **Sealed High** | `80 78 15 00` vs `80 78 1d 00` at helper entry. |
| Exact key (not nearest / not lower_bound-as-hit) | **Sealed High** | lower_bound walk then **`key < node.key → end`** (`7C` path). Equality only survives. Miss → end → body returns **0**. |
| L-1 same node* shape (no double-deref) | **Sealed High** | Same helper + same `*out` / `+0x10` as L path. Competing double-deref story falsified. |
| Product order Balance × frac × Scaler | **Sealed High** | Body: `movss [esi+0x144]`; `mulss [edi+0x10]`; `mulss [esi+0x140]`. |
| Trunc toward zero **in this VA** | **Sealed High** | Final `(int)((float)nLevelSpan * flSpanMult)` only. |
| Bias **not** in this VA | **Sealed High** | No load of `0x00aaa6d0` in body. Caller CompleteObjective ±bias after calc. Image float `8e 06 00 3f` = **0.5001f**. |
| Caller set (grant vs presentation) | **Sealed High** | xrefs (fresh): `0x005341c0` grant; `0x008ac594`/`0x008ac5e9` toast; `0x0051f521` float wrap. **No advance path.** |
| Body purity (no char XP write) | **Sealed High** | Only map loads + arithmetic; grant via `CVOGReaction_AddExperience` is caller. |

### Global VAs (from body immediates)

| Symbol (registry) | VA | Role |
|---|---|---|
| `g_pQuestXpLookupMap_INFERRED` | `0x00b0424c` | map this for quest find |
| `g_pQuestXpLookupMapEnd` | `0x00b04250` | end sentinel compare |
| `g_nQuestXpLookupReady` | `0x00b04254` | lazy-load flag |
| `g_pExperienceLevelMap_INFERRED` | `0x00b04240` | map this for level find |
| `g_pExperienceLevelMapEnd` | `0x00b04244` | end sentinel compare |
| `g_nExperienceLevelTableReady` | `0x00b04248` | lazy-load flag |
| `g_flMissionXpRoundBias` | `0x00aaa6d0` | **caller** only; 0.5001f |

### Caller bias contract (grant path only)

```
n = Mission_ComputeObjectiveXp(obj)     // trunc int HERE
f = (float)n
if f >= 0:  f = f + g_flMissionXpRoundBias   // +0.5001f
else:       f = f - g_flMissionXpRoundBias   // -0.5001f
CVOGReaction_AddExperience(char, (int)f, PacketOrNonKill)
```

Toast / `FUN_0051f510` call the calculator for **display** (chat + floater); they do **not** apply bias or AddExperience.

---

## 4. State mutations

**None** on character from this function. Lazy-load ensure-* helpers may write ready flags / maps (loader side effect only).

---

## 5. Gaps (remaining)

1. **R2** — WAD/runtime row payloads for `tQuestXPLookup` / `tExperienceLevel` (worked example XP=320 is arithmetic-consistent with `docs/XP.md` tables if those rows load as documented; not image-static sealed).
2. Ensure* loader / map product names still `_INFERRED` (VAs above are sealed; names are registry labels).
3. **R4** — Negative/zero scaler edges (no body clamp; pure float product can go non-positive).
4. **R5** — Live mission-complete XP measurement vs calc + bias.
5. Bit-exact / binary-diff harness open.

**Verdict:** Formula body + map-node protocol + caller partition faithful. Safe to port as pure calc; grant path must apply bias separately. **accept-with-gaps.**
