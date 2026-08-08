# Review B (skeptical / adversarial): `aa_0051f8e0` LookupRaceDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f8e0` |
| **VA** | `0x0051f8e0` |
| **Canonical name** | `LookupRaceDisplayName_Inferred` (**Inferred**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0051f8e0_LookupRaceDisplayName_Inferred.md` |
| **System** | skills-abilities / client race display |
| **Live tools** | Independent decompile + `read_memory` + callers/xrefs + caller decompiles |
| **Verdict** | **accept-with-gaps** — accept pure race leaf; reject combat / thiscall / ring / class-table / runtime claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Combat helper / `Named_CalleeOf_Named_Combat_*` | **Falsified** — only callers are `FUN_00845360` / `FUN_00846820` UI requirements; no combat xrefs |
| 2 | `__thiscall` / ECX character | **Falsified** — entry loads stack `[esp+4]` only; no ECX use |
| 3 | Owns TLS localization ring | **Falsified** — returns imm rodata; ring is `007a69d0`/`007a6de0` in callers |
| 4 | Heap / mutable return | **Falsified** — `mov eax, imm32` of string VAs |
| 5 | Class display table (Commando/Engineer/…) | **Falsified** — strings are Human/Mutant/Biomek/Unknown only; class table is `0x0051f940` |
| 6 | Same function as `Character_GetRaceDisplayName` `0x00521800` | **Falsified** — different VA; wrapper embeds cascade + ring; does not call this leaf |
| 7 | Jump-table switch | **Falsified** — sub/jz cascade; no table |
| 8 | RET 4 / stdcall cleanup | **Falsified** — plain `c3` at all exits |
| 9 | Product method name proven | **Rejected** — English map High; symbol Inferred |
| 10 | Runtime Confirmed / Terminal true | **Rejected** — no Launcher; Terminal **false** |
| 11 | Race id −1 returns `"Unknown"` path is caller's contract | **Nuanced** — leaf would return Unknown if called with −1, but both live callers gate on vfunc `+0x14 != -1` before call |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf CF / product strings | **Confirmed** | Wrong UI race text |
| cdecl 1-arg ABI / plain RET | **Confirmed** | Stack imbalance |
| Static return lifetime | **Confirmed** | Spurious free |
| Callers = item + craft UI | **Confirmed** | Wrong system placement |
| Product symbol English | **None** | Overclaim |
| Enum completeness beyond 0/1/2 | **High for implemented map** | Extra races would hit Unknown |

---

## 3. Decompiler pitfalls (must survive port)

1. Do not invent ECX-this from the character race wrapper dual.
2. Do not pull TLS ring into this unit.
3. Do not free the return pointer.
4. Keep cascade order 0→Human, 1→Mutant, 2→Biomek (not alphabetical).
5. Ghidra analyze signature `undefined FUN_0051f8e0(void)` is wrong — trust decompile `char*` + machine EAX imm.
6. Parent label **"Required Faction"** is product UI text for the race line; do not invent a separate faction-id table inside this leaf.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Full 0/1/2/else English map as implemented | PDB / design-doc method name |
| cdecl leaf used by craft/item requirements UI | That this is the only race→string path in the client |
| Static C-string return | Heap ownership / localization tables elsewhere |
| Peer of class lookup leaf | Merge with short-code twin `0x0051f910` without dual |

---

## 5. CF challenge of Review A

- CF + ABI + strings Confirmed: **agree**
- Role High / product symbol Inferred: **agree**
- accept-with-gaps: **agree**
- No Runtime Confirmed: **agree**

**Verdict:** **accept-with-gaps**
