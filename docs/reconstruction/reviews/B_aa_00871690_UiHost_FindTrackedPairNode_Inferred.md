# Review B (skeptical / adversarial): `aa_00871690` UiHost_FindTrackedPairNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00871690` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-R OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_00871690_UiHost_FindTrackedPairNode_Inferred.md` |
| **System** | client UI / vehicle-garage host residual |
| **Dual status** | **Present** |
| **Verdict** | **accept** on CF + ABI + offsets; **reject** overclaims on key domain / product class |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Unlocks on every exit | **Holds** — both end and match paths check `+0x650` then LeaveCS |
| 2 | Matches three keys / payload at +0 | **Falsified** — only `+8` and `+0xc` compared |
| 3 | Allocates or mutates nodes | **Falsified** — pure find; no store to node |
| 4 | `ret` without stack cleanup | **Falsified** — `ret 8` |
| 5 | Fastcall / no this | **Falsified** — `mov esi,ecx`; callers use `mov ecx,esi` |
| 6 | Keys are proven TFID | **Fail** — Tentative only; does not block accept |
| 7 | Legacy VOGClient seed name is role | **Falsified as primary** — role is list find; VOGClient is parent-seed noise |
| 8 | Needs `disassemble_bytes` | **Falsified** — decompile + `read_memory` seal body |

---

## 2. Decisive evidence

### Exit hex (`0x00871720`…)

`… 8b c7 5f 5e 5d 5b 83 c4 08 c2 08 00` + int3 pad.

### Entry hex

`83 ec 08 53 55 56 8b f1 33 c0 81 c6 28 06 00 00 …` → `this+0x628` list base.

### Sibling consumer (`0x008718a0`)

Already dual-sealed: calls this with two stack keys, tests EAX, zeros `*node`, refreshes. Confirms return is node pointer not boolean-only.

### List lock helper

`FUN_004294f0` enters CS at list+4 and sets flag list+0x28 — maps to host `+0x62c` / `+0x650` when list = host+0x628.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Match CF | **High** | Wrong node returned |
| Unlock paths | **High** | CS leak / double leave |
| Offsets | **High** | Wrong host layout |
| Product name | **Tentative** | Naming only |
| Key domain | **Open** | Mis-modeled caller keys |

---

## 4. What would falsify accept

1. Additional xrefs with different ABI (e.g. no ret 8).
2. Body compares more/other fields than +8/+0xc.
3. Different image build bytes.

None observed.

---

## 5. Verdict

**accept.** Compact list find is byte-complete. Prefer `UiHost_FindTrackedPairNode_Inferred` over VOGClient seed alias. Residual: product symbol + key semantics + runtime golden only.
