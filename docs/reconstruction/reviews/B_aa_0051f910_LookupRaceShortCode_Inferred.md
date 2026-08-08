# Review B (skeptical / adversarial): `aa_0051f910` LookupRaceShortCode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f910` |
| **VA** | `0x0051f910` |
| **Canonical name** | `LookupRaceShortCode_Inferred` (**Inferred**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0051f910_LookupRaceShortCode_Inferred.md` |
| **System** | skills-abilities / client race short codes |
| **Live tools** | Independent decompile + `read_memory` + callers/xrefs + call-site context + caller decompile |
| **Verdict** | **accept-with-gaps** — accept pure race short-code leaf; reject VOG-chain / thiscall / English-merge / class-table / path-suffix / runtime claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | VOGClient chain helper / `Named_CalleeOf_*VOGClient*` | **Falsified** — sole xref is `FUN_00871150` @ `0x00871273` UI formatter; no VOG-object method body |
| 2 | Same function as English twin `LookupRaceDisplayName` `0x0051f8e0` | **Falsified** — different VA; returns HUM/MUT/BIO not Human/Mutant/Biomek |
| 3 | Same as class short `FUN_0051fa10` | **Falsified** — 1-arg race only; class short is 2-arg class×race with COM/ENG/… |
| 4 | Same as path suffix `BuildRaceClassSuffix` `0x0051f550` | **Falsified** — no global buffer; returns static `"HUM"` not `"_h"` tokens |
| 5 | `__thiscall` / ECX character | **Falsified** — entry loads stack `[esp+4]` only; no ECX use |
| 6 | Owns TLS localization ring | **Falsified** — returns imm rodata; no ring callees |
| 7 | Heap / mutable return | **Falsified** — `mov eax, imm32` of string VAs |
| 8 | Class display table (Commando/Engineer/…) | **Falsified** — strings are HUM/MUT/BIO/Unknown only |
| 9 | Jump-table switch | **Falsified** — sub/jz cascade; no table |
| 10 | RET 4 / stdcall cleanup | **Falsified** — plain `c3` at all exits; caller `ADD ESP,4` |
| 11 | Product method name proven | **Rejected** — English short map High; symbol Inferred |
| 12 | Runtime Confirmed / Terminal true | **Rejected** — no Launcher; Terminal **false** |
| 13 | Race id −1 returns `"Unknown"` is caller's contract | **Nuanced** — leaf would return Unknown for any non-{0,1,2}; caller passes low nibble of packed byte (0..15) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf CF / product short strings | **Confirmed** | Wrong UI race codes |
| cdecl 1-arg ABI / plain RET | **Confirmed** | Stack imbalance |
| Static return lifetime | **Confirmed** | Spurious free |
| Sole caller = UI formatter | **Confirmed** | Wrong system placement |
| Distinct from English twin | **Confirmed** | Merge would break craft/item English path |
| Product symbol English | **None** | Overclaim |
| Enum completeness beyond 0/1/2 | **High for implemented map** | Extra races would hit Unknown |

---

## 3. Decompiler pitfalls (must survive port)

1. Do not invent ECX-this from character race wrappers.
2. Do not pull TLS ring into this unit.
3. Do not free the return pointer.
4. Keep cascade order 0→HUM, 1→MUT, 2→BIO (not alphabetical; not English full names).
5. Ghidra analyze signature `undefined FUN_0051f910(void)` is wrong — trust decompile `char*` + machine EAX imm.
6. Do not merge with English twin, class short peer, or `_h/_m/_b` path-suffix builder.
7. Reject scaffold VOGClient chain name; sole structural caller is residual UI host.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Full 0/1/2/else short map as implemented | PDB / design-doc method name |
| cdecl leaf used by UI level/class/race short line | That this is the only race→string path in the client |
| Static C-string return | Heap ownership / localization tables elsewhere |
| Twin of English race display leaf | Merge with English twin without dual |
| Shared `"Unknown"` rodata with English twin | That all race strings share one table |

---

## 5. CF challenge of Review A

- CF + ABI + short strings Confirmed: **agree**
- Role High / product symbol Inferred: **agree**
- accept-with-gaps: **agree**
- No Runtime Confirmed: **agree**
- Sole caller sealed: **agree**

**Verdict:** **accept-with-gaps**
