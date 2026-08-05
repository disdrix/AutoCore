# Review B (skeptical / adversarial): `aa_004b6fc0` FUN_004b6fc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6fc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b6fc0_FUN_004b6fc0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always runs after activate | Gated by `this+0x1FC != 0` | **Falsified unconditional** — gate required |
| 2 | Mutates host active flag | Body only walks/reads list + calls play helpers | **Falsified** — no `+0x0B` write |
| 3 | Same list as primary FX `+0x1EC` | Head is `+0x1F8` | **Confirmed different list** |
| 4 | Copy is string-only | `mov ecx, 0x32` + `sub esp, 0xC8` dword block copy | **Falsified** — **0xC8-byte** struct dump |
| 5 | Is mission-complete only | Called from shared FX host `004b8dc0` (weapon fire path) | **Falsify exclusive mission** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate `+0x1FC` / list `+0x1F8` | **High** | Spurious or missed secondary plays |
| Payload at `node[2]` | **High** | Wrong object |
| 0x32-dword copy size | **High** | Stack/buffer mismatch |
| `00720670` full arg map | **Low–Medium** | Incomplete play parity |
| Log string product name | **High** (literal present) | Cosmetic only |

---

## 3. Cross-check against raw + bytes

```
raw:
  if (*(this+0x1fc)!=0 && list(+0x1f8) non-empty)
    for each payload: copy 0x32 dwords; 00720d40(); 00720670(); log

entry @ 004b6fc0:
  51 83B9FC010000 53555657 894C2410 744C
  8B81F8010000 8B18 3BD8 7440
  8B6B08 81ECC8000000 B932000000 8BF5

≡ A sealed structure. Sibling dual 004b8dc0 owns when this runs (activate only).
```

---

## 4. Surviving contract for AutoCore

```csharp
// After SpecialFxHost_SetActive(on: true) list processing:
void SpecialFxHost_PostActivate(Host h)
{
    if (h.Gate_1FC == 0) return;
    foreach (var n in h.List_1F8)
    {
        var copy = n.Payload.CloneBytes(0xC8);
        var audio = InterfaceSound_GetSingleton(); // FUN_00720d40
        InterfaceSound_RequestPlay(audio, copy);    // FUN_00720670 (args TBD)
        // optional debug: "Requesting play %s"
    }
}
```

- Client cosmetic path; not combat authority.

---

## 5. Open questions

1. Full signature of `FUN_00720670`.
2. Whether `+0x1F8` entries are same schema as `+0x1EC` FX entries.
3. Runtime / differential verification.

**Verdict:** **accept**
