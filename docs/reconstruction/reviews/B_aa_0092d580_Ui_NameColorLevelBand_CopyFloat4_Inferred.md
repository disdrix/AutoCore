# Review B (skeptical / adversarial): `aa_0092d580` Ui_NameColorLevelBand_CopyFloat4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092d580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/band map; host/table English residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is skill accuracy / combat level band | Callers are UI name color + mission dialog text color | **Falsified as combat** |
| 2 | Returns ARGB immediately | Copies 16 B floats; parent multiplies ×255 | **Falsified** — float4 out |
| 3 | Same as palette `00930f40` | Different VA/ABI/tables | **Falsified** |
| 4 | levelDiff 0 and −1 share a slot | Bytes: 0→+0xC14; −1/−2→+0xC04 | **Falsified** |
| 5 | Host is always `clientCtx` from name color | Mission dialog uses its own ESI host | **Host is table owner**, not one global type sealed |
| 6 | Scaffold name CalleeOf_NpcDialog is product | Multi-caller leaf | **Superseded** by role name |
| 7 | Product name without string | No demangle | **`_Inferred` required** |
| 8 | Decompiler unsigned `param_2 < 0x80000000` differs from bytes | Maps 0 → +0xC14 vs −1/−2 → +0xC04 | **Survives as equivalent** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Band offsets / thresholds | **High** | Wrong difficulty color |
| 16 B copy leaf | **High** | Wrong out size |
| UI name-color consumer | **High** | Mis-file under combat |
| Host formal type | **Open** | Layout only |
| Float contents | **Open** | Visual residual |
| Runtime | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
0092d580  cmp edx, 7 / jl …
          add ecx, 0xC54 …
; … ladder …
          mov esi, [ecx]
          mov edx, eax
          mov [edx], esi
          … +4 +8 +0xC …
          pop esi
          ret
```

Live 2026-08-04 ≡ 2026-07-23 raw decompile.

---

## 4. Surviving contract

```
Ui_NameColorLevelBand_CopyFloat4(host, levelDiff, outFloat4);
// outFloat4 = host.table[band(levelDiff)]  // 8 bands @ +0xBE4, stride 0x10
// name path: ARGB = 0xFF000000 | pack(out[0..2] * 255)
```

**Verdict:** **accept**.
