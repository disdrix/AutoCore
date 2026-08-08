# Review B (skeptical / adversarial): `aa_004ce5c0` Character_TownInventoryFallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-118) |
| **Counterpart** | `reviews/A_aa_004ce5c0_Character_TownInventoryFallback_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `disassemble_function` + callers/xrefs + `get_assembly_context`. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Unequip-only helper (parent-seed sole role) | **Falsified** — also `FUN_008012f0` ×2 (mode-3 + free-slot miss) |
| 2 | Bare `ret` / no stack cleanup | **Falsified** — three `c2 04 00` |
| 3 | ECX = character; stack = mode | **Falsified** — body flags on ECX; call sites push character and load mode into ECX |
| 4 | Body mutates inventory / free-slot search | **Falsified** — pure predicate; no stores; no callees |
| 5 | Flags live on character `DAT_00d1b6d8` | **Falsified** — unequip sets ECX=`DAT_00d1b644`; character is stack null-gate only |
| 6 | Same as sibling `004ce5f0` (object vcall gate) | **Falsified** — no MI adjust, no `vtbl+0x210`; simpler null+flags only |
| 7 | Non-leaf / has external CALLs | **Falsified** — analyze classification leaf |
| 8 | Product-proven name “TownInventory” without gaps | **Unfounded** — role inferred from `+0xcbc` locker path; PDB open → `_Inferred` required |
| 9 | thiscall with 0 stack args (signature `void`) | **Falsified** — Ghidra listing `undefined FUN_004ce5c0(void)` is wrong; decompiler + bytes show 1 stack arg + `ret 4` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Predicate CF + ABI | **High** | inventing inventory side effects |
| ECX=modeHost / stack=character | **High** | inverted port args |
| Flag offsets | **High** | wrong gate polarity |
| Flag English / town-vs-locker labels | **Low–Open** | docs reuse other `+0xf5` meanings without proof |
| Structural name + `_Inferred` | **High** as structural | over-claiming product name |

---

## 3. Cross-check against raw + bytes

```
Character_TownInventoryFallback_Inferred:  ; ECX=modeHost, [esp+4]=character, ret 4
  cmp [esp+4], 0; jz false
  if modeHost[+0xf5] return true
  return modeHost[+0x7e] != 0
```

Any clean plate that stores inventory cells, calls free-slot search, treats ECX as character, or omits stack cleanup is **wrong** for this VA.

Sibling `004ce5f0` must stay distinct: it adds object MI + `vtbl+0x210(0)` before the same flag pair.

---

## 4. Surviving contract for AutoCore

```c
// Port as pure gate — do not invent free-slot or packet side effects here
bool Character_TownInventoryFallback_Inferred(ModeHost* mode, Character* ch);

// Unequip / move: if free-slot fails && gate(mode, ch) → use ch->lockerGrid (+0xcbc)
// Preserve offsets +0xf5 / +0x7e without inventing product flag names until sealed.
// Do not merge with Character_HostModeGateForObjectV210 (004ce5f0).
```

---

## 5. Open questions

1. PDB / product symbol.
2. Mode-host flag English; identity of `DAT_00d1b644` vs `client+0xe04`.
3. Product “town” vs sealed layout “locker” for `+0xcbc`.
4. Runtime / differential.

**Verdict:** **accept-with-gaps**
