# Review B (skeptical / adversarial): `aa_004bc180` Object_RegisterListed

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc180` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-E) |
| **Counterpart** | `reviews/A_aa_004bc180_Object_RegisterListed.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x004bc180` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function **is** `Mission_VOG_DEBUG_STOP` / pure debug halt | Body allocates handles, hash buckets, multi-caller register | **Falsified** — log tag only on invalid COID |
| 2 | cdecl / no stack cleanup | epilogue `C2 04 00` | **Falsified** — **`ret 4`**, one stack arg |
| 3 | Always throws / never returns | already-listed path `return 0`; success `return 0` | **Falsified** |
| 4 | Always mission-notifies | notify only type 0x12/special 0xe/0x14 and flag bit5 | **Falsified** — conditional |
| 5 | Single handle write | primary `+0xdc` plus optional `+0xd0/+0xd4/+0xd8` | **Falsified multiplicity** |
| 6 | Key always type from meta | `vtbl+0x208` forces `0x30` | **Falsified** dual key |
| 7 | `"already listed"` is fatal | returns 0 without throw | **Falsified** — soft |
| 8 | Three-rep diverges | live ≡ raw ≡ bytes | **Falsified** |
| 9 | Clean may invent PDB name as proven | no PDB | **Open English** — structural name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 4 + object* | **High** | stack corruption on port |
| COID validation + HRESULT throws | **High** | silent bad objects |
| already-listed soft return | **High** | double-register bugs |
| Handle offsets + type gates | **High** | wrong list membership |
| Mission notify conditions | **High** | spurious mission fails |
| Type 0x12/0xe/0x14 product English | **Open** | doc-only mislabel |
| Runtime / bit-exact | **Open** | shipping image |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  invalid COID → VOG_DEBUG_STOP + throw 0x80070057
  mode gate → throw
  already listed → log + return 0
  key = vtbl+0x208 ? 0x30 : type
  hash ensure 0x2c node
  handles via FUN_004bc680 → +0xdc [+0xd0 +0xd4 +0xd8]
  conditional FailMissionNotify

bytes:
  prolog 55 8B EC 6A FF 68 4C 17 9A 00 …
  COID loads [esi+0x160]/[esi+0x164]
  push "VOG_DEBUG_STOP" @00a15844
  push already-listed @009cb4a8
  B8 30 00 00 00  (key imm)
  6A 2C          (node size)
  C2 04 00       (ret 4)
```

**No conflict** on owned CF. Product symbol open. Parent-seed mission-debug name **rejected** as primary.

---

## 4. Surviving contract for AutoCore

```csharp
// Object_RegisterListed @ 0x004bc180
// retail: ECX = listing manager, stack Object*, ret 4
// returns 0 on success OR already-listed; throws on invalid COID / OOM / bad secondary HR

int RegisterListed(ListingContext mgr, Object obj)
{
  // Do NOT implement as debug-stop.
  // Do NOT always fire mission-fail notify.
  // Preserve soft-duplicate return distinct from throw paths.
}
```

---

## 5. Residual risks

1. `FUN_004bc680` handle object layout not owned here.
2. Whether manager is strictly “mission” vs global world list — **multi-caller** evidence favors shared listing service.
3. No runtime hit confirmation in this dual.
