# Review A (reconstruction fidelity): `aa_005083f0` CVOGHBBase_EndOrDestroy

| Field | Value |
|---|---|
| **Stable ID** | `aa_005083f0` |
| **VA** | `0x005083f0` |
| **Canonical name** | `CVOGHBBase_EndOrDestroy` (inferred) |
| **Ghidra symbol** | `FUN_005083f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_005083f0_CVOGHBBase_EndOrDestroy.md` |
| **System** | `heartbeat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared **HB end / destroy** helper installed on many HB vtables at slot **`+0x18`** (see e.g. `g_pVtbl_CVOGHBOKToCastAgain` @ `0x009ce1dc`).

Two stack flags (MSVC thiscall):

1. **`flag_onEnd` (`[ebp+8]`):**  
   - `0` → zero `this+0x18` (list/owner link), **skip** OnEnd.  
   - nonzero → **`vtbl+0x14` OnEnd** virtual call.
2. **`flag_hard` (`[ebp+0xc]`)** (consumed in SEH tail `FUN_0050843d`):  
   - With live list owner → `FUN_005085b0` remove + further teardown.  
   - Else soft-mark `this+0x20 = 1` and clear `this+0x18`.

Decompiler signature shows only one `char` arg; **second stack arg is real** (`cmp [ebp+0xc]` in body / tail). Callers push **two** values (e.g. flipper early path `push 0; push 0`).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005083f0_FUN_005083f0.md` | Decompiler under-args |
| Annotated / clean | scaffold | CF partial |
| Live decompile | Ghidra MCP `0x005083f0` | Under-modeled arity |
| Live `read_memory` | `0x005083f0` 80 B | **flag0 / vtbl+0x14 / ebp+0xc sealed** |
| Tail | `FUN_0050843d` decompile | Hard vs soft path |
| Vtbl note | `reviews/a_0051e3b0.md` | Slot `+0x18` = this VA |
| Callers | Ghidra xrefs | Direct CALL + many DATA vtbls |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=`CVOGHBBase*` | **High** | `mov esi, ecx` |
| Stack arg0 = OnEnd gate | **High** | `cmp [ebp+8], bl` |
| Arg0==0 → `*(this+0x18)=0`, no vcall | **High** | `mov [esi+0x18], ebx` |
| Arg0≠0 → `(*vtbl)[+0x14](this)` OnEnd | **High** | `call [eax+0x14]` |
| Stack arg1 at `[ebp+0xc]` used in tail | **High** | Bytes + `FUN_0050843d` |
| Soft path: `this+0x20=1`, clear `+0x18` | **High** | Tail decompile |
| Hard path: `FUN_005085b0` when owner list present | **High** | Tail gates on `this+0x18` and `+0xb0` |
| Installed as vtbl `+0x18` on many HB types | **High** | 70+ DATA xrefs |
| Direct CALL sites include flipper ctor, mission patrol, weapon track | **High** | Caller list |
| Product name | **Probable** | Inferred EndOrDestroy |

---

## 4. Control flow seal (`read_memory`)

```text
push ebp / mov ebp,esp / SEH setup
xor ebx,ebx
cmp [ebp+8], bl          ; flag_onEnd
mov esi, ecx
jnz do_onend
  mov [esi+0x18], ebx    ; clear owner/list
  jmp tail
do_onend:
  mov eax,[esi]
  mov ecx,esi
  call [eax+0x14]        ; OnEnd
tail:  ; FUN_0050843d outline
  cmp [ebp+0xc], bl      ; flag_hard
  ... if hard && this+0x18 && *(list+0xb0): FUN_005085b0; continue teardown
  ... else: mov byte [esi+0x20],1; mov [esi+0x18],0; restore SEH; ret
```

---

## 5. Callers (direct)

| Function | Role |
|---|---|
| `FUN_005075f0` flipper ctor re-entry | `(0,0)` soft abort of partial HB |
| `CVOGHBMissionPatrol_Fn6` | Patrol HB end path |
| `Vehicle_CreateWeaponTrackAction` | Weapon-track HB teardown |
| `FUN_005cc5b0`, `FUN_00626160`, `FUN_006261e0` | Other HB factories / ends |
| **DATA** many vtbls `+0x18` | Virtual dispatch destroy/end |

---

## 6. Gaps / open

1. Exact product name / whether unified with scalar dtor thunk.
2. Full body of `FUN_005085b0` / `FUN_0050846f` (list unlink details).
3. Decompiler still reports single `char` — trust asm arity **2 stack bytes/dwords**.
4. Runtime not run.

**Verdict:** **accept-with-gaps** — dual-flag CF + OnEnd slot + soft/hard tail sealed; list-unlink callees residual.
