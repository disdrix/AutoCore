# Review B (skeptical / adversarial): `aa_0073be50` GlyphCacheList_ForEach_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073be50` |
| **VA** | `0x0073be50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0073be50_GlyphCacheList_ForEach_OnDeviceReset_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 36 B + sole xref context + callee decompile + W37-AE GlyphCache +0x2c |
| **Agent** | W38-U OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void` / no args is complete ABI | Bytes: `MOV EAX,[EBX+8]`; caller `MOV EBX,[device+0x758]` | **Falsified** — EBX container sealed |
| 2 | Callee takes no args | Bytes: `MOV ESI,[EDI+0x2C]; CALL 00755820`; callee uses `unaff_ESI` | **Falsified** — ESI payload sealed |
| 3 | This is GlyphCache factory | Factory is sibling `0073bc50` (W37-AE); this only walks + calls hook | **Falsified** |
| 4 | ECX thiscall | No ECX use; EBX live-in | **Falsified thiscall** |
| 5 | Returns meaningful non-zero | `XOR EAX,EAX` before RET always | **Falsified** — always 0 |
| 6 | Product manager name sealed | Only offset `device+0x758` known | **Accepted gap** |
| 7 | Payload is definitely GlyphCache* | +0x2c matches GetOrCreate node payload; callee layout fits 0xB8 GlyphCache | **High, not PDB-proof** — name stays `_Inferred` |
| 8 | Scaffold gfxDevice name is product | Structural for-each helper | **Rejected scaffold** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Circular list walk | **Confirmed** | Miss caches on reset |
| EBX + ESI ABI | **Confirmed** | Caller/callee break |
| Sole Reset success-path use | **Confirmed** | Wrong lifecycle |
| GlyphCache payload family | **High** | Wrong type port |
| Product manager English | **Open** | Doc-only |
| `00755820` full semantics | **Open** | Incomplete rebuild port |
| Runtime | **Open** | — |

---

## 3. Cross-check vs GlyphCache family

W37-AE: `GlyphCache_GetOrCreate` returns map-node payload at **+0x2c**. This walker loads the same offset into ESI before the reset hook. Callee `FUN_00755820` touches +0xC/+0x10 uint16 vector and flags +0x64/+0x68 — inside GlyphCache size **0xB8** (W35-H). Consistent family; not re-proven as PDB class here.

---

## 4. Byte anchors

```text
0x0073be50: 8B 43 08       ; EAX = [EBX+8] sentinel
            57             ; push EDI
            8B 38          ; EDI = *sentinel (first node)
            3B F8          ; cmp node, sentinel
            74 16          ; empty → done
            56             ; push ESI
            …
0x0073be60: 8B 77 2C       ; ESI = [node+0x2c]
            E8 B8 99 01 00 ; CALL FUN_00755820
            8B 3F          ; EDI = [node] next
            3B 7B 08       ; cmp next, [EBX+8]
            75 F1          ; loop
            5E 33 C0 5F C3 ; pop; return 0; pop; ret
```

---

## 5. What would reverse the seal?

- Proof EBX is not container (caller loads EBX from device+0x758 immediately before CALL) — not observed.
- Proof empty-list path skips RET 0 — contradicted by `XOR EAX,EAX`.
- Proof payload offset is not +0x2c — contradicted by `MOV ESI,[EDI+0x2C]`.

None observed for sealed CF/ABI. Product English and full hook dual remain open → **accept-with-gaps**.

**Verdict:** **accept-with-gaps**
