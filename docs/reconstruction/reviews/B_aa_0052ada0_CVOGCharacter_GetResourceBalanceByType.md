# Review B (skeptical / adversarial): `aa_0052ada0` CVOGCharacter_GetResourceBalanceByType

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ada0` |
| **VA** | `0x0052ada0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0052ada0_CVOGCharacter_GetResourceBalanceByType.md` |
| **System** | `missions-progression` (+ shared resource consumers) |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** on CF/ABI/map; **reject** listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Free function / no `this` | **Falsified** — `MOV ESI,ECX`; map at `ESI+0x584` |
| 2 | `__cdecl` with character on stack | **Falsified** — character in **ECX**; **`RET 4`** consumes typeId only |
| 3 | Returns bool / presence only | **Falsified** — returns full **dword balance** or **`-1`** |
| 4 | Missing key returns `0` | **Falsified** — `OR EAX,0xFFFFFFFF` → **`-1`** |
| 5 | Hash table / CNDHash at `+0x584` | **Overstated** — callee is ordered-map find `FUN_00418b80` (tree), not `CNDHash_LookupByKey` |
| 6 | Value at `node+0x8` (hash payload style) | **Falsified** — `MOV EAX,[EAX+0x10]` |
| 7 | End sentinel is null | **Falsified** — compares to **`[this+0x588]`** node pointer |
| 8 | Mutates balance / spends resource | **Falsified** — no stores; pure lookup |
| 9 | Mission-only helper | **Falsified** — **dozens** of xrefs (UI tooltips, item costs, etc.) |
| 10 | Product name is proven “GetCurrency” | **Unproven** — role sealed; English open |
| 11 | Decompiler two-arg form of `FUN_00418b80` is ABI truth | **Misleading** — live pushes **out\*** + **key\*** + map `this` |
| 12 | Package is bit-exact / runtime complete | **Fail** — static dual only |

---

## 2. Decisive dataflow (raw + live)

```
this = ECX (character)
out_node = MapFind(map@this+0x584, key=typeId)
if out_node == *(this+0x588): return -1
return *(out_node + 0x10)
```

Live decompile body **matches** frozen raw CF. Assembly **corrects** decompiler’s collapsed `FUN_00418b80` argument list and seals `RET 4`.

Requirements site: `PUSH type; MOV ECX,char; CALL` → `CMP EAX, threshold; JGE pass else -1`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + typeId stack + RET 4 | **High** | Stack corruption in ported call |
| Map base `+0x584` / end `+0x588` | **High** | Wrong character field → always −1/wrong |
| Value at `node+0x10` | **High** | Read wrong field as balance |
| Missing → −1 (not 0) | **High** | Treat missing as free resource |
| Read-only body | **High** | Invent spend side-effect on check |
| Discipline consumer semantics | **High** | Auto-grant / offer without cost gate |
| Product English name | **Open** | Docs naming only |
| Single global “currency” vs multi-type map | **Probable** (multi-type via key) | Schema oversimplification |
| Runtime / differential | **Open** | Residual parity risk |

---

## 4. Offset / ABI attack checklist

| Check | Result |
|---|---|
| Entry uses ECX as this | **Pass** (`MOV ESI,ECX`) |
| Stack formal width dword | **Pass** (`RET 4`) |
| Map displacement 0x584 | **Pass** (imm in bytes `84 05 00 00`) |
| End displacement 0x588 | **Pass** (imm `88 05 00 00`) |
| Value displacement 0x10 | **Pass** (`8b 40 10`) |
| No `RET` bare (cdecl) | **Pass** — both exits `RET 4` |
| Requirements only caller | **Fail claim** — many xrefs |

---

## 5. What would overturn this dual

1. Image change at VA (re-read bytes).
2. Proof any call site passes non-character ECX into this body for a different map layout.
3. Proof `+0x10` is not the numeric balance used by cost/Discipline compares.
4. RTTI/string proving a different product name **without** changing role (name only — CF stands).

Until then, CF + ABI + map layout stand at **High**.
