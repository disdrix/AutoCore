# Review B (skeptical / adversarial): `aa_004044c0` CombatFloater_UninitializedCopy_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004044c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004044c0_CombatFloater_UninitializedCopy_0x38_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | This VA is the pod-copy leaf | **Falsified** — leaf is `FUN_004046f0`; this only calls `FUN_00404730` |
| 2 | Element size 4 / dword vector | **Falsified** — worker stride **0x38** |
| 3 | Fills from a single template value | **Falsified** — range-to-range copy (src advances with dst); fill is `0x00402ea0` / `0x004044e0` |
| 4 | Owns growth / `operator_new` | **Falsified** — pure copy helper |
| 5 | Part of XP formula | **Falsified** — storage relocate only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trampoline-only body | High | Mis-assign complexity to wrong VA |
| 0x38 via callee | High | Wrong floater layout |
| Distinct from fill-n | High | Corrupt insert semantics |
| Formal names from Ghidra | Low | Do not trust param labels |

---

## 3. Cross-check against raw / live

```
raw ≡ live: single CALL to 0x00404730 then return.
FUN_00404730: loop +0x38, FUN_004046f0(dst, src).
Parent dual already lists this VA as relocate helper.
```

---

## 4. Surviving contract for AutoCore

```
CombatFloater_UninitializedCopy_0x38(srcBegin, srcEnd, dst):
  // trampoline → FUN_00404730
  copy each 0x38 POD from [srcBegin,srcEnd) into consecutive dst slots
  used by CombatFloaterVector_InsertN realloc path
```

---

## 5. Open questions

1. Seal formal ABI map from parent call sites only (not decompiler formals).
2. Optional dual on `FUN_00404730` if still scaffold-only.

**Verdict:** **accept-with-gaps**
