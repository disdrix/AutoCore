# Review B (skeptical / adversarial): `aa_0043b800` Gfx_DepthStencilFormat_ToBpp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043b800` |
| **VA** | `0x0043b800` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0043b800_Gfx_DepthStencilFormat_ToBpp_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 49 B + JT/IDX + 9 xrefs + call-site context + twin `0040ead0` + Clear/score callers |
| **Agent** | W38-U OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void` / no formal is complete ABI | Bytes: EAX is sole input; 5× `MOV EAX,imm; RET` / `XOR EAX,EAX; RET` | **Falsified void** — EAX in/out sealed |
| 2 | This is color/texture format bpp | Twin `0040ead0` covers D3DFMT 0x14/0x15/…; this covers 0x47–0x50 depth enums only | **Falsified merge** |
| 3 | Returns bytes not bits | Callers always `SHR 3` after call for byte size | **Falsified** — returns bits |
| 4 | Product name sealed from PDB | No string in unit; D3DFMT match is enum-level only | **Accepted gap** — `_Inferred` |
| 5 | Scaffold gfxDevice callee name is product | Multi-caller utility (surface size, score, Clear, Reset) | **Rejected scaffold** |
| 6 | Missing formats in band return non-zero | IDX holes map to JT slot 4 → `XOR EAX,EAX` | **Falsified** — return 0 |
| 7 | Stack formals exist | No stack touch; plain `RET` | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf bpp mapper role | **Confirmed** | Wrong mem-acct / surface size |
| EAX ABI + plain RET | **Confirmed** | Caller contract break |
| Depth-stencil D3DFMT band | **Confirmed** | Port wrong format set |
| Distinction from `0040ead0` | **Confirmed** | Color/depth counter mix-up |
| Product English name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs Clear stencil table

`FUN_0075ebd0` maps same enum to **stencil bit counts** (0x49→1, 0x4B→8, 0x4F→4) independently of this unit's bpp table — corroborates depth-stencil domain without depending on this function's return for stencil width.

---

## 4. Byte anchors

```text
0x0043b800: 83 C0 B9          ; format -= 0x47
            83 F8 09          ; cmp 9
            77 26             ; ja → return 0
            0F B6 80 48 B8 43 00  ; movzx eax, IDX[eax]
            FF 24 85 34 B8 43 00  ; jmp JT[eax]
0x0043b816: B8 20 00 00 00 C3 ; return 32
0x0043b81C: B8 0F 00 00 00 C3 ; return 15
0x0043b822: B8 18 00 00 00 C3 ; return 24
0x0043b828: B8 10 00 00 00 C3 ; return 16
0x0043b82E: 33 C0 C3          ; return 0
```

---

## 5. What would reverse the seal?

- Proof EAX is not the format (callers load format into EAX immediately before CALL) — not observed.
- Proof returns bytes (would make `SHR 3` divide by 8 again → nonsense) — contradicted by all mem-acct sites.
- Proof this handles color formats 0x14/0x15 — those return 0 here; color uses `0040ead0`.

None observed.

**Verdict:** **accept**
