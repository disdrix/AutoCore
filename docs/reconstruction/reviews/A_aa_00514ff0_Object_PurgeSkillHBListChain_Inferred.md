# Review A (reconstruction fidelity): `aa_00514ff0` Object_PurgeSkillHBListChain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514ff0` |
| **VA** | `0x00514ff0` |
| **Canonical name** | `Object_PurgeSkillHBListChain_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md` |
| **System** | skills-abilities / object HB bookkeeping |
| **Wave** | W19-N OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Object helper: when gate byte **`this+0x25`** is non-zero, invoke **`CNDDoubleList_InvokePredicateAndRemove_Inferred`** on list **`*(this+0xB0)`** with predicate **`LAB_00512eb0`** (stop/remove **CVOGHBSkillBase** HBs; optional set **`hb+0x6a4`** when ctx≠0). Then if **`*(this+0xAC)`** ≠ 0, **recurse** on that linked object with stack arg **0**.

Used from skill apply, weapon fire, and damage paths to clear in-flight skill heartbeats on a host object (and one linked hop).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00514ff0_FUN_00514ff0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00514ff0_FUN_00514ff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00514ff0.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Object_PurgeSkillHBListChain_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00514ff0_Object_PurgeSkillHBListChain_Inferred.md` |
| Fresh decompile | Ghidra `decompile_function` + `force_decompile` @ `0x00514ff0` |
| Body image | Ghidra `read_memory` 54 B @ `0x00514ff0` — **`C2 04 00`**, `mov ecx,[esi+0xB0]`, self-call |
| Predicate bytes | `read_memory` @ `0x00512eb0` + RTTI strings `@0x00af8cec` / `@0x00af8d98` |
| List utility dual | `aa_004e2600` CNDDoubleList_InvokePredicateAndRemove_Inferred |
| Sibling | `FUN_00515030` (flag `+0x26`, loop `+0xAC`) |
| Analyze complete | worker; 9 xrefs; callees list util + self |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact image diff. No parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=object; **1 stack dword**; **`RET 4`** | **Confirmed** | `mov esi,ecx`; `C2 04 00` |
| Gate `this+0x25` (u8); enter when ≠0 | **Confirmed** | `cmp [esi+0x25],0` / `jbe` skip |
| List this = `*(this+0xB0)` pointer | **Confirmed** | `mov ecx,[esi+0xB0]` not `lea` |
| Args to list: predicate `0x00512eb0`, `&stackArg`, flag **0** | **Confirmed** | push order |
| Recurse: ECX=`*(this+0xAC)`, stack **0** | **Confirmed** | `mov ecx,[esi+0xAC]`; `push 0`; `call self` |
| Decompiler `FUN_00514ff0(0)` without ECX rebind | **Falsified as ABI** | bytes rebind ECX |
| Predicate type tag 1 → CVOGHBSkillBase RTTI | **Confirmed** | strings + cast immediates |
| On match: optional `+0x6a4=1` if `*ctx≠0`; `vtbl+0x18(1,0)`; remove | **High** | predicate body |
| Role = purge skill HB list + one link hop | **High** | CF + callers |
| Product English method name | **Open** | `_Inferred` required |
| Full English for `+0x25` / `+0xAC` / `+0x6a4` | **Open** | |
| Runtime / bit-exact | **Open** | not run |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Gate `+0x25` | Yes |
| List remove via `0x004e2600` | Yes (named util) |
| Linked `+0xAC` recurse with 0 | Yes |
| `RET 4` | Yes (bytes; raw decomp omitted) |
| No invent of multi-hop beyond one recursive call | Yes (recurse may chain if each node links) |

### Recovered CF

```c
// void __thiscall Object_PurgeSkillHBListChain_Inferred(Object* this, int ctxHost)
// RET 4
if (this->flag_25 != 0) {
  CNDDoubleList_InvokePredicateAndRemove_Inferred(
      this->pHBList_B0, LAB_00512eb0, &ctxHost, /*nullPayload=*/0);
}
if (this->pLinked_AC != 0)
  Object_PurgeSkillHBListChain_Inferred(this->pLinked_AC, 0);
```

---

## 5. Callers (context only; not owned)

| Caller | Site role | Typical stack arg |
|---|---|---|
| `Skill_ApplyStatusEffectLocal` | pre-effect clear path | **0** (also has near-inline same pattern) |
| `FUN_0056d520` Weapon_StartFire… | optional when nested list non-null | **0** |
| `FUN_005c8fe0` / `FUN_004f62e0` | damage / shield paths | often **1** (sets hb+0x6a4) |
| `FUN_005d9290`, `FUN_00812a60`, others | object bookkeeping | varies |

---

## 6. Gaps

1. Product / demangled method name.
2. Field English (`+0x25`, `+0xAC`, `hb+0x44`, `hb+0x6a4`).
3. Whether recurse depth is intentionally one-logical-link vs multi-hop chain (body allows multi if each has `+0xAC`).
4. Full second arm of any adjacent LAB after predicate (not required for this unit''s call).
5. Runtime / bit-exact image diff.

---

## 7. Verdict

### **accept-with-gaps**

**Accept because:** body bytes seal thiscall+RET4, list*@+0xB0, flag@+0x25, link@+0xAC, predicate identity and SkillBase stop/remove behavior; three-rep raw≡live decompile CF with ABI corrected by bytes; list util already dual-sealed. Product English and field names remain open under `_Inferred`.
