# Review B (skeptical / adversarial): `aa_005305b0` CVOGCharacter_SetMissionCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_005305b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-I) |
| **Counterpart** | `reviews/A_aa_005305b0_CVOGCharacter_SetMissionCounter.md` |
| **Scratch** | `tmp/a_005305b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is AddMissionCounter (`00530610`) | **Falsified** — hit is `MOV [node+0x14],value` not `ADD`; **ret 8** not **ret 0xC** |
| 2 | This is GetResourceBalance (`0052ada0`) | **Falsified** — writes; no `-1` miss return; miss inserts |
| 3 | Three stack formals like Add | **Falsified** — epilogue `C2 08 00` |
| 4 | Map only at `+0x588` | **Falsified** — object `+0x584`, compare head `+0x588` |
| 5 | Free function / stdcall | **Falsified** — `MOV EDI,ECX`; thiscall |
| 6 | Hit updates +0x10 (Get field) | **Falsified** — hit only +0x14; miss zeros +0x10 then sets +0x14 |
| 7 | Decompiler map this is complete | **Falsified as ABI** — machine sets ECX = char+0x584 before find/operator[] |
| 8 | Product name is retail | **Overstated** — structural / sibling-mirrored only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Absolute set role | **High** | Wrong progress / reward math |
| thiscall + ret 8 | **High** | ABI break |
| Miss insert vs hit assign | **High** | Double-insert / missed write |
| +0x14 write site | **High** | Desync with Get if port confuses +0x10 |
| Product counter English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH ECX/ESI/EDI; this→EDI
LEA ESI,[EDI+0x584]
CALL find(map=ESI, &node, &key)
CMP node, [EDI+0x588]
JZ miss:
  CALL operator[](map=ESI, &key)
  *mapped=0; mapped[1]=value; RET 8
hit:
  [node+0x14]=value; RET 8
```

Live 2026-07-29 ≡ raw 2026-07-23 CF. Callers: `FUN_00530670` Set(key,0); `FUN_0094e530` token Set(type,amount).

---

## 4. Surviving contract for AutoCore

```
// Absolute set (not add):
CVOGCharacter_SetMissionCounter(character, key, value);
// Preserve: map this = char+0x584; head compare char+0x588;
// miss → OperatorIndex then mapped{0,value}; hit → node+0x14 = value;
// ret 8 (two stack formals). Do not use Add's ret 0xC / third seed.
// Do not assume GetResourceBalance(+0x10) reflects Set's +0x14 without a sync path.
```

---

## 5. Verdict

Adversarial pass **confirms** A: set-vs-add, ABI, map offsets, miss/hit sealed; product English + dual-field open → **accept-with-gaps**.
