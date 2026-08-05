# Review B (skeptical / adversarial): `aa_005617c0` WorldObj_SnapshotHostRefsAndUnbind_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005617c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-T) |
| **Counterpart** | `reviews/A_aa_005617c0_WorldObj_SnapshotHostRefsAndUnbind_Inferred.md` |
| **Scratch** | `tmp/a_005617c0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is rehome (`00560f70`) | **Falsified** — rehome is the consumer after HBAI swap; this only snapshots + unbinds before swap |
| 2 | ECX is the world object | **Falsified** — caller `MOV ECX,EDI` with EDI=`*(obj+8)` manager; obj is stack #1 |
| 3 | Single stack arg / ret 4 | **Falsified** — two pushes; epilogue `C2 08 00` |
| 4 | Copies all host children blindly | **Falsified** — only entries with `+0xc` or `+0x10` equal to obj |
| 5 | Leaves host list intact | **Falsified** — compact-remove on each match |
| 6 | Always hard-unbinds object | **Overstated** — `005614f0` defers when `manager+0x12c==1` |
| 7 | Product mode-7 name is retail | **Overstated** — code `7` only; `_Inferred` name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mode-7 snapshot producer role | **High** | Rehome desync / lost island glue |
| thiscall + ret 8 | **High** | ABI break |
| Match fields +0xc/+0x10 | **High** | Wrong entries snapshotted |
| Compact remove | **High** | Dangling host list refs |
| Unbind vs defer tail | **High** | Reentrancy / double free |
| Entry product type | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
SUB ESP,14; MOV EBP,ECX; host=[EBP+0x2c]; snap.count=0
loop host+0x58: match entry+0xc/+0x10 to obj
  grow snap; push; vcall entry+0x28; vcall host+0xc; compact; i--
FUN_005614f0(manager, &obj, obj)
POP*; ADD ESP,14; RET 8
```

Sole xref `005d44d0` inside SwitchHBAI; pairs with `00560f70` when old mode == 7. Live ≡ raw CF.

---

## 4. Surviving contract for AutoCore

```
// On HBAI mode leave from code 7, before controller swap:
WorldObj_SnapshotHostRefsAndUnbind_Inferred(manager, obj, &snapshot);
// After swap:
WorldObj_RehomeLinksFromSnapshot_Inferred(manager, obj, &snapshot);
// Must preserve: match +0xc/+0x10, compact remove, vcalls, 005614f0 tail, ret 8.
// Do not skip snapshot or rehome will see empty/wrong list.
```

---

## 5. Verdict

Adversarial pass **confirms** A: snapshot/unbind contract + ABI sealed → **accept**.
