# Review A (reconstruction fidelity): `aa_005accf0` CrazyTaxi_AccumulateLegTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_005accf0` |
| **VA** | `0x005accf0` |
| **Canonical name** | `CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred` |
| **Ghidra** | `FUN_005accf0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W30-M) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` |
| **System** | CrazyTaxi objective time-budget leg accumulation |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

For `CVOGObjectiveRequirement_CrazyTaxi`, accumulate one **leg** of mission time budget: world-space Euclidean distance between a source pose and a destination taxi-stop object, convert by continent/map **scale**, weight by TimeLimit **Percent** from the Val12 map at `this+0x8c` (keyed by stop count), add into a running float; if `stopsKey < 1` also add **5.0f**.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005accf0` — **≡ raw 2026-07-23** |
| Body bytes | `read_memory` — exclusive end `0x005acee7` (**503 B**); `c2 14 00` |
| Constant | `read_memory 0x00aaa688` → `00 00 a0 40` = **5.0f** |
| Meta | `get_function_by_address`, `analyze_function_complete`, callees |
| Layout corroboration | CrazyTaxi ctor `FUN_005adb20`; XML dump `FUN_005acf10` (`TimeLimit` / `GenericTargetCOID`) |
| Xrefs | full-image E8 + absolute-ptr scan — **zero** static refs |

**Not performed:** Launcher, runtime, bit-exact, ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
float __thiscall AccumulateLegTime(
    void *crazyTaxi, void *actor, int stopsKey,
    float acc, int fromIndex, int toIndex);
// RET 0x14; return in x87 (float10 in decomp)
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Scale load via actor+0x250 → +0x634 | Yes |
| fromIndex&lt;0 → GetPos vtbl+0x1a0 | Yes |
| else TFID resolve `004bb1c0` + pos@+0x84 | Yes |
| Dest resolve + Δpos + SQRT | Yes |
| Val12 walk isnil@+0x19 / key@+0x0C | Yes |
| Conditional Dec; Percent@+0x14 | Yes |
| stopsKey&lt;1 → +5.0f | Yes |
| `ret 0x14` | Yes (bytes) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CrazyTaxi method (layout match) | **High** | +0x4c / +0x8c / RTTI family |
| Distance / scale / Percent formula | **High** | decomp + constant seal |
| `ret 0x14` thiscall | **High** | bytes |
| Product English name | **Inferred** | AccumulateLegTime |
| Bracket semantics (floor vs exact) | **Tentative** | Dec after lower_bound |
| Static callers exist | **None found** | may be dead |
| Uninit src if fromIndex resolve fails | **High residual** | decomp path |

---

## 6. Gaps

1. Product English / demangled method name.
2. No static callers — ownership of call graph open (dead code vs dynamic dispatch not in image).
3. Exact TimeLimit bracket policy after Dec (floor vs exclusive) product intent.
4. Clean plate summarizes dual-reg walk — raw remains authority.
5. Runtime / bit-exact / differential — open.

---

## 7. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005accf0_FUN_005accf0.md` |
| Annotated | `docs/reconstruction/raw/aa_005accf0_FUN_005accf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` |

**Verdict:** **accept-with-gaps**
