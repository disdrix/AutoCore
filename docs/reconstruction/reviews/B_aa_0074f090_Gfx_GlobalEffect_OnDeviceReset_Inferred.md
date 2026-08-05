# Review B (skeptical / adversarial): `aa_0074f090` Gfx_GlobalEffect_OnDeviceReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074f090` |
| **VA** | `0x0074f090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0074f090_Gfx_GlobalEffect_OnDeviceReset_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 46 B + sole xref call-site + sibling `0074f0c0` + parent fail plate |
| **Agent** | W38-W OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void`/no formal is complete ABI | Prologue `CMP [EAX+0xC]`; caller loads EAX before CALL | **Falsified no-formal** — **EAX=holder** |
| 2 | Returns raw HRESULT | `SETGE`/`SUB 1` collapses to 0/−1 | **Falsified raw HRESULT** |
| 3 | Null inner is failure | Null path returns 0 | **Falsified** |
| 4 | Same as shutdown `FUN_0074f0c0` | Sibling uses +0x10c/+0x114; this uses +0x118 + status map | **Falsified merge** |
| 5 | ECX thiscall this | No ECX load of holder; EAX only | **Falsified ECX-this** |
| 6 | Not Global Effect | Parent fail string exact product plate | **Falsified** |
| 7 | Scaffold Named_CalleeOf is product name | Structural + plate-backed Inferred only | **Rejected scaffold sole** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX holder + `+0xC` + `vtbl+0x118` | **Confirmed** | Caller contract break |
| 0/−1 status map | **Confirmed** | Wrong Reset chain predicate |
| Global Effect rebuild role | **Confirmed** | Wrong factory stage |
| Product iface type | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs caller

`GfxDevice_Reset` factory chain (@ `0x0075f329`):

```text
MOV EAX, [EBP+0x760]
MOV EAX, [EAX+4]       ; holder into EAX
CALL FUN_0074f090
CMP EAX, EBX           ; EBX=0
JGE  continue_success
; else vog_LogMessage … "Failed to Reset() device on Global Effect" → return -1
```

Matches EAX formal and 0/−1 contract (`JGE` treats −1 as fail).

---

## 4. Byte anchors

```text
0x0074f090: 83 78 0C 00 74 19 …     ; [EAX+0xC] null?
            8B 40 0C 8B 08 50
            FF 91 18 01 00 00       ; vtbl+0x118
            33 D2 85 C0 0F 9D C2
            83 EA 01 8B C2 C3       ; 0 / -1
```

---

## 5. What would reverse the seal?

- Proof formal is ECX or stack — contradicted by prologue and caller EAX setup with no stack args / no `RET n`.
- Proof return is raw status — contradicted by SETGE/SUB1 before RET; caller uses `JGE` vs 0.
- Proof null is error — contradicted by zero path returning 0 and success continue.

None observed.
