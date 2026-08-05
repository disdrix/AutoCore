# Review B (skeptical / adversarial): `aa_0073e980` Gfx_EffectMap_ReleaseAllEntries_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073e980` |
| **VA** | `0x0073e980` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0073e980_Gfx_EffectMap_ReleaseAllEntries_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 47 B + sole xref + callee decomps + parent Reset call site |
| **Agent** | W38-W OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **erases** the map | Loop only release + iterator++; no erase/delete-node call | **Falsified erase** — release-only |
| 2 | Simple intrusive list, not tree | `FUN_004425f0` is successor with isnil@`+0x11`, parent/right walks | **Falsified list** — tree iterator |
| 3 | Payload offset ≠ `+0xC` | Bytes `8B 40 0C 50` before call | **Falsified** |
| 4 | ECX/thiscall this formal | No this use; only global `DAT_00d1ee68` | **Falsified thiscall** |
| 5 | Infinite loop if empty mishandled | Empty: `CMP begin,head; JE done` | **Sealed empty** |
| 6 | Scaffold gfxDevice callee name is product | Multi-step Reset helper; structural name only | **Rejected scaffold sole name** |
| 7 | Product map English sealed | No local strings; only parent path | **Accepted gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Release-all walk role | **Confirmed** | Wrong Reset shutdown port |
| Tree head global + iterator++ | **Confirmed** | Wrong container family |
| Payload @`+0xC` | **Confirmed** | Wrong field |
| Non-erasing | **Confirmed** | Incorrect clear semantics |
| Product type English | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs caller

`GfxDevice_Reset` shutdown (@ `0x0075f145`):

```text
; prior: Release some COM @ ESI
E8 …                 CALL FUN_0073e980   ; no args
MOV EDX, [EBP+0x760]
MOV ESI, [EDX+4]
CALL FUN_0074f0c0    ; sibling lost-device pass
```

Fits void global drain immediately before Global-Effect lost-device family.

Neighbor `FUN_0073e800` (unowned): single-entry `FUN_0073e780` then conditional erase vs `DAT_00d1ee68` — confirms same map family without merging roles.

---

## 4. Byte anchors

```text
0x0073e980: 51 56 8B 35 68 EE D1 00 …  ; head
            8B 40 0C 50 E8 …          ; payload + release
            8D 54 24 04 E8 …          ; &cur → iterator++
            75 E6 5E 59 C3            ; loop / epilog
```

---

## 5. What would reverse the seal?

- Proof nodes are unlinked inside this function — contradicted by callees (release + pure iterator++ only).
- Proof `DAT_00d1ee68` is not tree head — contradicted by iterator isnil layout and `FUN_0073e800` erase compare to same symbol.
- Proof non-void ABI (stack args / RET n) — contradicted by plain `C3` and argless call site.

None observed.
