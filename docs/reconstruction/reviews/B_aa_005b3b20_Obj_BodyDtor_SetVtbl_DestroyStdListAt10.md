# Review B (skeptical / adversarial): `aa_005b3b20` Obj_BodyDtor_SetVtbl_DestroyStdListAt10

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3b20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-N) |
| **Counterpart** | `reviews/A_aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Trust raw decompile as CF | **Falsified as complete** — decompile shows CALL `FUN_00497360` with ECX still = this; bytes are `ADD ECX,0x10` + **JMP** |
| 2 | This is a full object dtor freeing all fields | **Overstated** — only vtbl + list at +0x10; other members not touched here |
| 3 | Product class is known from vtbl adjacency | **Falsified** — next bytes are `"vs.1.1…"` shader text, not a class name string |
| 4 | Multiple direct callers | **Falsified** — sole code xref is scalar dtor `FUN_005b44d0` |
| 5 | List offset is guessed | **Falsified as guess** — ctors `LEA EDI,[ESI+0x10]` then init head/size via `FUN_005b43b0` |
| 6 | Name is retail symbol | **Overstated** — structural inferred; no plate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vtbl + list destroy tail | **High** | Wrong teardown / UAF |
| List at +0x10 | **High** | Destroy wrong member |
| Only body role (not scalar) | **High** | Double-delete if mis-port |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against bytes + callers

```
; FUN_005b44d0 scalar
MOV ESI, ECX
CALL 005b3b20          ; body
TEST flags,1 / delete
RET 4
```

```
; body bytes
MOV dword ptr [ECX], 0x009d95b4
ADD ECX, 0x10
JMP 00497360           ; StdList_Destroy_FreeHead
```

Ctor twin: `MOV [ESI],0x9d95b4`; `LEA EDI,[ESI+0x10]`; `CALL 005b43b0` (sentinel buy) — matches list placement.

---

## 4. Surviving contract for AutoCore

```
// Port:
*this = final_vtbl;                 // 0x009d95b4
StdList_Destroy_FreeHead(this+0x10);
// Do NOT free other host fields here.
// Scalar delete (flags&1) is FUN_005b44d0, not this unit.
```

---

## 5. Verdict

Adversarial pass **confirms** A on bytes/ABI and **rejects** decompile CALL shape → **accept-with-gaps** (product class open).
