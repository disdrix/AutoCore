# Review B (skeptical): `aa_00611f20` Collect_Action

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611f20` |
| **VA** | `0x00611f20` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_Action` (challenged name below) |
| **Review date** | `2026-07-29` (dual residual strengthen) |
| **Reviewer role** | Skeptical independent counter-review |
| **Counterpart** | `reviews/A_aa_00611f20_CVOGObjectiveRequirement_Collect_Action.md` |
| **Verdict** | **accept-with-gaps** |
| **Dual residual** | **sealed (static)** — accept-with-gaps; do not promote clean as loot oracle |

---

## 1. Stance

Do not accept parent annotations, clean stubs, or chain prose without re-checking the binary. Prefer Ghidra decompile + vtable + constants over narrative. Challenge every “eventType”, “progress signal”, and “kill loot” label.

---

## 2. Inspected artifacts (independent residual re-check)

| Artifact | Result |
|---|---|
| Ghidra decompile `0x00611f20` | Full body re-fetched — matches `raw/aa_00611f20_FUN_00611f20.md` |
| `analyze_function_complete` | callers=[]; xrefs DATA `009e12c8` only; callees match named GiveItem/Count/RNG/place |
| Vtable `read_memory 0x009e12c4` | dword1 = `0x00611f20` → slot **+0x04** under Collect `PTR_FUN_009e12c4` |
| Floats `read_memory` | `DAT_00aaa638`≈1/65536; `DAT_00a0f718`=0.01; `DAT_00aaa8a8`=300.0 |
| Ctor `0x00611690` | `*this = PTR_FUN_009e12c4`, `this[3]=2` (RequirementType collect) |
| Count `0x005711c0` | thiscall grid enumerator; Action passes includeBroken=`0` (same as Eval) |
| Clean Action.cpp | Inventory arm only; **kill path absent** — cannot validate clean vs binary for loot |
| Eval `0x00611940` | Cargo + count; **no** Action call — separate vtable method |

---

## 3. Challenges

| # | Challenge | Outcome |
|---|---|---|
| C1 | Is this Collect, or mislabeled Deliver / generic objective Action? | **Collect.** Vtable entry is second slot of Collect ctor vtable (type **2**). Deliver uses `PTR_FUN_009e0f24` / type **3**. RTTI string family is Collect. |
| C2 | Is the name “Action” proven, or inventing MSVC RTTI method names? | **Role High, original name Tentative.** Binary has no demangled method name. Slot +0x04 is family “Action/EventHandler”; prefer `Collect_Action` as registry alias only. |
| C3 | Is `param_4` really “event type” or a retyped object pointer? | **Integer discriminator 0 vs 1 is High.** Outer test is pointer-null then exact compare to `(int*)1`. Decompiler type `int*` is wrong; semantic is small int event code. Values **beyond** 0/1 fall through to return 0. |
| C4 | Inventory path “progress signal” — does return 1 complete the objective? | **Not shown.** Only low-byte 1 when CBID matches and adjusted count still **&lt; NumToCollect**. Callers virtual; no static consumer proves mission-state write. Could mean “interested / handled / keep listening.” Treat as **progress-related bool**, not completion. **Sealed demotion.** |
| C5 | Does kill path always drop when percent rolls? | **No.** Gates: level band, cargo present, count &lt; need, optional-target match (or player race/class), `OptionalDropPercent > 0`, RNG success, actor flag/`+0x1c8` checks, char flag `+0x6b9`, `FUN_00404d70` template non-null, mission-hash / vtbl `+0xc` veto, then GiveItem. Many silent exits. **Sealed multi-gate.** |
| C6 | Can kill loot fire with zero OptionalTargetCBID entries? | **Non-player path: No.** Requires `0 < param_1[7]`. Empty list skips match/drop for `TargetIsPlayer==0`. Player-target uses race/class masks instead. **Sealed CF trap.** |
| C7 | Is pre-spawn `CountItemsByCbid` reliable in decompile? | **Intent High, SSA weak.** Result assigned to `uStack_38` while compare uses `iStack_3c`. Claim “count-under-need gates loot” only — **not** bit-exact stack. |
| C8 | Are `param_5`/`param_6` sealed product names? | **Probable only.** Inventory: `(int)param_5 == CBID`, `count - (int)param_6`. Kill: `(int)param_5` vs optional target CBIDs. Float ABI leftover; **int casts sealed**. |
| C9 | Convoy path = free global party grant? | **No.** When flag + convoy ptr set: iterate members within **300.f**, each needs hash + vtbl `+0xc` pass. Proximity+hash gated. **Sealed structure.** |
| C10 | Client GiveItem = authoritative collect progress? | **Reject as sealed.** Client allocates/places; server inventory/mission authority not in this function. Parallel Eval re-counts cargo; server `0x2071` separate. |
| C11 | Is clean.cpp reconstruction truth for loot? | **No.** Clean stubs loot to `return 0`. Fidelity hangs on **raw/Ghidra**. Inventory arm is readable paraphrase (branch reordered). |
| C12 | Drop formula: percent 0–100 or 0–1? | **Scaled by 0.01** (constants re-read). Matches XML percent-style 0–100 **Probable**; content dump not re-run. Formula **High**. |
| C13 | Does this function update Eval fraction itself? | **No.** No mission slot float writes; only GiveItem side effects + bool return. Progress fraction remains Eval’s job. **Sealed negative.** |
| C14 | Can kill path return low-byte 1 after successful spawn? | **No.** Kill exits mask low byte to 0 (`& 0xffffff00` / fallthrough). **Only** inventory arm returns 1. **Sealed polarity.** |
| C15 | Are unused `param_3`/`param_7` secret control flags? | **No evidence.** Empty storage / unread in body. Presence is family ABI padding **Probable**; roles Open only if callers pass meaningful values (virtual — untraced). |

---

## 4. Claims accepted (after challenge)

| Claim | Confidence | Note |
|---|---|---|
| Collect vtable Action slot body | **High** | Memory + ctor |
| Dual null/0 vs 1 control split | **High** | CF |
| Cargo via `char+0x250`, grid at `+0x2b0` | **High** | Same as Eval |
| Inventory: CountByCbid + CBID match + under NumToCollect → return 1 | **High** | Exact predicates |
| Kill: optional targets / player filters → drop% → GiveItemByCbid | **High** | Structure; multi-gate |
| Kill return polarity always low-byte 0 | **High** | Residual seal |
| Field offsets CBID / NumToCollect / drop% / convoy / targets | **High** | XML + use sites |
| Drop/convoy constants via `read_memory` | **High** | Residual re-verify |
| Clean incomplete for loot | **High** | File content |
| Runtime / server sealed | **N/A — open** | Not accepted |

---

## 5. Claims rejected or demoted

| Claim (if asserted) | Disposition |
|---|---|
| “Original name Collect_Action / Collect_EventHandler” | Demote to **inferred role** |
| “Return 1 completes the collect objective” | **Rejected** without caller proof |
| “Always spawns on kill when drop% set” | **Rejected** — multi-gate |
| “param_4 is int*” | Decompiler artifact; treat as **event int** |
| Clean kill path ≡ binary | **Rejected** |
| Kill success returns progress bool 1 | **Rejected** — masks to 0 |
| Full loot end-to-end sealed (chain residual) | **Still open** for runtime/server — static structure sealed |

---

## 6. Uncertainty register (remaining open)

1. Virtual dispatcher that passes event codes 0/1 (mission director? inventory notify? death notify?).
2. Meaning of return 1 to that caller (continue, credit, UI tick).
3. Whether `param_6` is previous count, event delta, or another quantity — only algebra `count - param_6` is known.
4. Exact product type of `param_8` (killer vs local player actor vs event source).
5. Live behavior when convoy member fails GiveItem (loop continues; return masked) — structure known, live not captured.
6. Interaction with server QuestItemPickup / MissionCollectProgress (out of static unit).
7. Template path `FUN_005001f0` / `FUN_00404d70` object model depth — called, not dual-sealed as separate units.
8. Nested player race-table walk product types (`+4/+4/+0xac/+0x3c`, race `@+0x532`, class `@+0x531`).

---

## 7. Comparison with Review A

| Topic | Agree? | Skeptical note |
|---|---|---|
| Class + vtable slot | **Yes** | — |
| Dual event arms | **Yes** | Emphasize unknown codes &gt;1 |
| Field map + constants | **Yes** | Residual re-read confirms |
| Inventory return = “progress signal” | **Partial** | A: progress-related; B: bool interest only — both reject completion |
| Kill return polarity always 0 | **Yes** | Residual strengthen |
| Clean fidelity | A notes gap | B: clean non-authoritative for loot |
| Optional-target empty edge | **Yes** | Behavioral trap |
| Drop % scaling | A High formula | B: percent-vs-unit content **Probable** |
| Residual seal static dual | **Yes** | accept-with-gaps |

---

## 8. Residual disposition (B)

| Item | Status |
|---|---|
| Structure dual 0/1 + cargo bridge + inventory predicates | **Sealed** |
| Kill multi-gate + drop formula constants + convoy 300.f | **Sealed** |
| Empty optional non-player trap + kill return polarity | **Sealed** |
| Return-1 completion semantics | **Demoted / Open consumer** |
| Clean full kill CF | **Open by design** (raw oracle) |
| Runtime / server / dispatcher | **Open** |

---

## 9. Verdict

**accept-with-gaps** — dual residual **sealed (static)**.

Accept static structure: Collect Action virtual, kill-loot vs inventory-recount arms, cargo/CountItemsByCbid bridge, XML-backed fields, GiveItem/convoy side effects, kill-vs-inventory return polarity, verified drop/convoy constants. Do **not** accept: original method name, completion semantics of return 1, clean kill-path reconstruction, server authority of client GiveItem, or end-to-end live loot seal.

Residual work (out of dual write scope): runtime event-code capture; optional promote clean kill path from raw; consumer of return value via vtable call sites in mission event dispatcher.
