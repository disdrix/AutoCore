# Review B (skeptical / adversarial): `aa_006170b0` Skill_HB_SpawnEntities_Precheck_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006170b0` |
| **VA** | `0x006170b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_006170b0_Skill_HB_SpawnEntities_Precheck_Inferred.md` |
| **Evidence** | Live decompile + multi-region `read_memory` + vtbl + FormatFailure table |
| **Agent** | W20-N OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is the spawn **Execute** method | Execute is `0x00615020` at vtbl+0x2c; this is +0x1c; no spawn/Enqueue | **Falsified Execute** |
| 2 | Final arms never return (decompiler WARNING) | Bytes: `mov eax,8` / `xor eax,eax` + `ret 8` after delete | **Falsified noreturn** |
| 3 | Return 8 means success | FormatFailure case 8 = “too many of that summon.” | **Falsified success** |
| 4 | Return 0x10 is stunt/level (old myth) | FormatFailure 0x10 = SUMMONCOUNT_TOTAL; 0x12 is stunted | **Falsified** |
| 5 | Always enforces total summon cap | Only when float `+0x16c == 0`; 100.0 skips all | **Falsified always-cap** |
| 6 | Direct CALL callers | Only DATA xref at vtbl slot | **Falsified static calls** |
| 7 | `ret 4` / one stack arg | All exits `C2 08 00` | **Falsified** |
| 8 | Product class name sealed | No RTTI/string for `PTR_FUN_009d0ec4` English | **Accepted gap** |
| 9 | Histogram key is always clonebase without remap | Optional skill `+0x22` path remaps via vtbl/`FUN_005001f0` | **Falsified always-direct** |
| 10 | Same unit as `FUN_004c3f10` | That is count helper; this owns precheck policy | **Falsified merge** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Return codes + FormatFailure map | **Confirmed** | Wrong cast UI |
| Vtbl slot / sibling Execute | **Confirmed** | Wrong virtual binding |
| Histogram threshold gate | **Confirmed** | Wrong per-type limit |
| Product class / key field names | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs sibling / failure table

| Unit | Ownership |
|---|---|
| `0x006170b0` (this) | Precheck returns only |
| `0x00615020` | Execute spawns |
| `0x0054fa20` | Formats failure strings for codes this returns |
| `0x004c3f10` / `0x004c2e60` | Count / cap math (not owned) |

Do not merge Execute dual ownership into this VA.

---

## 4. Byte anchors

```text
0x006170b0: 55 8B EC 83 E4 F8 6A FF 68 72 86 9A 00 …
            … B8 02 00 00 00 … C2 08 00     ; return 2
            … 0F 2E 05 AC A7 AA 00 …        ; comiss 100.0f
            … B8 10 00 00 00 … C2 08 00     ; return 0x10
            … B8 08 00 00 00 … C2 08 00     ; return 8
            … 33 C0 … C2 08 00              ; return 0
0x009d0ee0: B0 70 61 00                     ; dword = 0x006170b0
```

---

## 5. What would reverse the seal?

- Live proof that vtbl+0x1c is post-execute cleanup (would reclassify role).
- Discovery that return 8 is success for a different consumer (contradicts FormatFailure).
- Bit-exact mismatch on skill offset map.

None observed from decompile + bytes + sibling dual + failure table.
