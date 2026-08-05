# Review B (skeptical / adversarial): `aa_009197a0` Client_FindFirstObjectInRadius

| Field | Value |
|---|---|
| **Stable ID** | `aa_009197a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_009197a0_Client_FindFirstObjectInRadius.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/15f callers; **falsify “nearest”** as min-distance |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function is true **nearest** object by Euclidean min | Loop returns **first** hash entry with dist² &lt; r²; no running min | **Falsified** — first-in-radius |
| 2 | Radius hard-coded **15** inside body | Body uses `param_1`; imm only at callers | **Falsified as body constant** — sealed as **caller 15f** |
| 3 | Alias `Named_VOG_DEBUG_STOP` is purpose | Strings are generic hash-lock asserts shared by many walkers | **Falsified** |
| 4 | Always scans world hash | Auto-patrol waypoint in-range + resolve **skips** hash | **Falsified** |
| 5 | Uses click UseObject **25f** | Callers push `0x41700000` = 15f; 25f is pick-hub only | **Falsified** |
| 6 | Distance uses sqrt / 2D only | 3-axis squared compare vs obj+0x80/84/88 | **Falsified** |
| 7 | `__cdecl` / no stack cleanup by callee | Epilogue `RET 4` | **Falsified** — stdcall 4 |
| 8 | Hidden fourth caller | `get_function_callers` + xrefs = 3 parents | **Falsified** |
| 9 | FUN_004e88e0 transforms basis | Decompile: copy 3 floats only | **Falsified** |
| 10 | Sends UseObject / 0x2072 itself | No packet in body; callers send | **Falsified** |
| 11 | Accepts radius **inclusive** | Condition continues while `r² <= dist²` → need **strictly &lt;** | **Sealed strict** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `RET 4` / float arg | **High** | Wrong ABI in reimpl |
| Caller imm 15.0f ×3 | **High** | Wrong Activate / complete range |
| First-in-radius not min-dist | **High** | Server/client “nearest” product mismatch |
| Waypoint short-circuit CF | **High** | Miss patrol prefer path |
| Hash lock + node links | **High** | Deadlock / skip objects |
| obj pos +0x80/84/88 | **High** | Wrong range gate |
| Predicate vfunc+0x64 | **Tentative** | May include invalid ghosts |
| Product name | **Open** | Registry churn only |
| Runtime | **Open** | Edge cases at r² == dist² |

---

## 3. Cross-check against raw + call sites

```
; entry 0x009197a0
; prolog: push ebp; mov ebp,esp; and esp,-10; sub esp,0x44
; EAX = [DAT_00d1b6d8]; adj this; CALL [vtbl+0x1a0] → float4*
; MOVSS copy xyzw; CALL FUN_004e88e0 (xyz copy)
; if patrol vector empty/far/unresolved:
;   lock hash *(DAT_00d1b644+0xe8f4)+0x1d
;   walk node+0x14 / +0x20; TFID* at +0xc
;   optional filter; Object_ResolveFromTFID
;   while null || r*r <= |obj.pos - player.pos|²
;   unlock
; RET 4  → EAX = object* or prior null/waypoint hit
```

Call sites (asm):

```
00927b2a  PUSH 0x41700000
00927b2f  CALL 0x009197a0
00927b34  MOV  EDI, EAX          ; Activate target

00810029  PUSH 0x41700000
0081002e  CALL 0x009197a0
00810033  TEST EAX, EAX         ; complete-objective match path

00921338  PUSH 0x41700000
0092133d  CALL 0x009197a0
00921342  MOV  ESI, EAX
```

Body re-decompile 2026-07-29 ≡ 2026-07-23 raw (no CF drift).

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `Client_FindFirstObjectInRadius` | **Accept INFERRED** — matches CF |
| `Client_FindNearestObjectInRadius` | **Reject** — implies min-distance |
| `Named_VOG_DEBUG_STOP_009197a0` | **Reject** — assert string only |
| `FUN_009197a0` | Keep as Ghidra residual synonym |

---

## 5. Residual opens (do not block seal of 15f helper)

1. Predicate field typing (`pTfid[1].dwCoidHi` overlay).
2. Whether `Client_EvalAutoPatrolWaypoint` can emit `0x20B3` as a surprise side effect when this helper runs during Activate (callee gates — document only).
3. `FUN_009210e0` whether ESI result is dead-store (parent residual).
4. Live multi-object-in-15f which object wins (hash order).

---

## 6. Verdict vs A

Agree with A on: ABI, 15f callers, waypoint-then-hash CF, squared 3D test, no packet in body, three callers.

Stronger wording: **do not document as “nearest”** without “first in traversal order within radius.”
