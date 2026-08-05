# Review A (reconstruction fidelity): `aa_00524520` CVOGCharacter_FindActiveObjectiveIdForInteract

| Field | Value |
|---|---|
| **Stable ID** | `aa_00524520` |
| **VA** | `0x00524520` |
| **Canonical name** | `CVOGCharacter_FindActiveObjectiveIdForInteract` |
| **Prior names** | `FUN_00524520`; misleading auto-alias `Named_VOG_DEBUG_STOP` (hash-lock assert string only) |
| **Review date** | `2026-07-29` (dual residual refresh — byte-level +0x40 walker) |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00524520_CVOGCharacter_FindActiveObjectiveIdForInteract.md` |
| **System** | `interaction-activation` (also mission active-objectives) |
| **Verdict** | **accept-with-gaps** (body + primary caller **High**; eval implementers / multi-site ECX still open) |

---

## 1. Purpose

`thiscall` on **character** (`ECX`), one stack arg **world object**, `ret 4`: walk the character’s **active objectives** hash at `char+0x548` and return the **objective id** (`*(instance+0x10)`) of the **first** objective whose evaluators match that object via `FUN_0059d9c0` → evaluator `vtable+0x40(character, world)`. Null object → **0**. Exhaust / no match → **0**.

Primary consumer: `Client_SendUseObject_IfInteractable` (`0x00930d70`) — uses return as **gate** (non-zero allow) **and** packet `IDObjective` `@+0x18` (`mov [esp+0x1c], eax`). Type-4 allow with no match therefore wires **0**, not −1.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (scaffold) | `docs/reconstruction/raw/aa_00524520_FUN_00524520.md` |
| Raw (named) | `docs/reconstruction/raw/aa_00524520_CVOGCharacter_FindActiveObjectiveIdForInteract.md` |
| Annotated | `docs/reconstruction/raw/aa_00524520_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_FindActiveObjectiveIdForInteract.cpp` |
| Function record | `docs/reconstruction/functions/aa_00524520_CVOGCharacter_FindActiveObjectiveIdForInteract.md` |
| Helper | `aa_0059d9c0` / `0x0059d9c0` (`CVOGObjective_MatchTargetEvaluators`) |
| Sibling walker | `FUN_005245d0` / `0x005245d0` → `FUN_0059da10` (`vtable+0x44`) |
| Contrast matcher | `Client_FindObjectiveMatchingTarget` `0x00525bd0` (returns **def\***, `vtable+0x38`, pending gate `+0x55c`) |
| Live decompile | Ghidra `0x00524520`, `0x0059d9c0`, sibling, IfInteractable, PickTarget (2026-07-29) |
| **Byte seal** | Ghidra `read_memory` @ `0x00524520`, `0x005245a0`, `0x0059d9c0`, `0x00930d70` (capstone-decoded) |
| Xrefs | 10 call sites (IfInteractable, PickTarget, PollBoundActions ×2, FUN_00490070, FUN_008a81a0, tooltip, …) |

---

## 3. Control flow (authoritative — decompile + bytes)

### 3.1 Walker `0x00524520` (bytes)

```
cmp  [esp+4], 0          ; world null?
push ebx
mov  ebx, ecx            ; EBX = character this
jnz  body
xor  eax, eax
pop  ebx
ret  4                   ; one stack arg

body:
push ebp / esi / edi
mov  edi, [ebx+0x548]    ; hash root
xor  esi, esi            ; node = 0
xor  ebp, ebp            ; result = 0
; lock hash+0x1d = 1 (assert HashError:TraversalLock / VOG_DEBUG_STOP)
loop:
  ; reload hash from [ebx+0x548]; assert lock
  ; node = first ? [hash+0x14] : [node+0x14]
  ; objInst (EDI) = node ? [node+8] : 0
  ; if !objInst → unlock
  mov  eax, [esp+0x14]   ; world (frame-adjusted)
  push eax               ; stack arg2 = world
  push ebx               ; stack arg1 = character
  mov  ecx, edi          ; this = objective instance
  call FUN_0059d9c0      ; MatchTargetEvaluators (+0x40)
  test al, al
  jz   loop
  mov  ebp, [edi+0x10]   ; objective id
unlock:
  mov  ecx, [ebx+0x548]
  pop  edi / esi
  mov  eax, ebp
  pop  ebp
  mov  byte ptr [ecx+0x1d], 0
  pop  ebx
  ret  4
```

### 3.2 Helper `0x0059d9c0` (bytes) — sole xref from walker

```
push ebx / ebp / esi / edi
mov  edi, ecx                ; this = objective
mov  esi, [edi+0x158]        ; eval begin
cmp  esi, [edi+0x15c]        ; eval end
je   ret0
mov  ebx, [esp+0x18]         ; world  (orig stack+8 after 4 pushes)
mov  ebp, [esp+0x14]         ; character (orig stack+4)
loop:
  mov  ecx, [esi]            ; evaluator*
  mov  eax, [ecx]            ; vtbl
  push ebx                   ; world
  push ebp                   ; character
  call dword ptr [eax+0x40]  ; *** vtable +0x40 ***
  test al, al
  jnz  ret1
  add  esi, 4
  cmp  esi, [edi+0x15c]
  jne  loop
ret0: xor al, al ; pops ; ret 8
ret1: mov eax, 1  ; pops ; ret 8   ; two stack args
```

### 3.3 Primary caller `Client_SendUseObject_IfInteractable` `0x00930d70` (bytes)

```
sub  esp, 0x20
push edi
mov  edi, eax                    ; target object (EAX in)
mov  eax, [esi+0xe04]
cmp  byte ptr [eax+0xf6], 0
jne  deny
mov  ecx, [esi+0xe98]            ; *** character = client+0xE98 ***
push edi                         ; world
call FUN_00524520
test eax, eax
jnz  allow
mov  ecx, [edi+0xa8]
cmp  dword ptr [ecx+0x38], 4     ; clone type 4 bypass
je   allow
deny: xor al, al ; pop edi ; add esp,0x20 ; ret
allow:
  add  edi, 0x160                ; TFID source
  ; pack TFID → [esp+0x0c..0x18]
  mov  dword ptr [esp+4], 0x2072 ; opcode @ packet+0
  mov  dword ptr [esp+0x1c], eax ; *** IDObjective @ packet+0x18 ***
  ; send via [esi+0xc78] vtbl+0x18 size 0x20
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall (Character* this, Object* world) → u32`, `ret 4` | **High** | Prologue `mov ebx,ecx` + `ret 4`; null on `[esp+4]` |
| Null world → 0 | **High** | Early `ret 4` with `xor eax,eax` |
| Hash root `char+0x548` = active objectives | **High** | `mov edi,[ebx+0x548]`; shared family |
| Traversal lock byte `hash+0x1d` | **High** | set 1 / clear 0; HashError strings |
| Chain: first `hash+0x14`, next `node+0x14`, payload `node+8` | **High** | Decompile + loop structure |
| Helper call: `ECX=obj`, push **character**, push **world** | **High** | Bytes at `0x005245a2`–`0x005245aa` |
| Helper `ret 8` (two stack args) | **High** | Epilogue `ret 8` |
| Evaluator range `[obj+0x158, obj+0x15c)` step 4 | **High** | Helper body |
| Match slot **vtable+0x40** | **High** | `call dword ptr [eax+0x40]` |
| Eval formals **(character, world)** thiscall on evaluator | **High** | push world; push char; ECX=eval\* |
| Return value = `*(objInst+0x10)` objective id | **High** | `mov ebp,[edi+0x10]` |
| Return 0 on exhaust / no match | **High** | `ebp` init 0 |
| First hash-order match wins | **High** | Break on first non-zero match |
| **Not** a pure boolean | **High** | Id stored to packet `@+0x18` |
| No pending-count gate at `+0x55c` | **High** | Absent (contrast `00525bd0`) |
| IfInteractable: `ECX = *(client+0xE98)` | **High** | Bytes `mov ecx,[esi+0xe98]` |
| IfInteractable: packet `@+0x18 = EAX` return | **High** | `mov [esp+0x1c], eax` with opcode at `[esp+4]` |
| Type-4 no-match wires **0** not −1 | **High** | Allow path reuses EAX after failed match |
| Name `CVOGCharacter_FindActiveObjectiveIdForInteract` | **Probable–High** | Role clear; retail symbol not recovered |
| Character ECX at **all** 10 xrefs | **Partial** | Primary sealed; tooltip/UI sites open |
| Which req types implement non-trivial `+0x40` | **Open** | Out of body scope |
| Runtime multi-active first-wins order | **Open** | Static only |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null gate + `ret 4` | **Yes** |
| Lock / traverse / unlock | **Yes** |
| Payload `node+8` | **Yes** |
| Helper arity `(obj, char, world)` | **Yes** — sealed by pushes + helper `ret 8` |
| Eval `vtbl+0x40(char, world)` | **Yes** |
| Return `+0x10` or 0 | **Yes** |

Scaffold `FUN_00524520.cpp` is a direct decompiler dump. Prefer named clean for product reading.

---

## 6. Contrast with related matchers (fidelity)

| Unit | Hash | Match | Returns | Extra gate |
|---|---|---|---|---|
| **This** `0x00524520` | `+0x548` | `0059d9c0` → eval **`+0x40`** | **id** `@+0x10` | none |
| Sibling `0x005245d0` | `+0x548` | `0059da10` → eval **`+0x44`** | **id** `@+0x10` | none |
| `FindObjectiveMatchingTarget` `0x00525bd0` | `+0x548` walk | inline eval **`+0x38`** | **def\*** | pending `+0x55c` count ≥ 1 |

Do **not** merge these three in ports.

---

## 7. Callers (xref inventory)

| Site | Role | Character ECX |
|---|---|---|
| `Client_SendUseObject_IfInteractable` `0x00930d8c` | Gate + packet `@+0x18` | **`*(client+0xE98)`** — **High** |
| `Client_InteractClickPickTarget` `0x00924da2` | Truthy OR with ForPick before IfInteractable | Residual (thiscall ambient) |
| `Client_Input_PollBoundActions` `0x00927b4e` / `0x00927bc3` | Truthy → IfInteractable | Residual |
| `FUN_00490070` `0x0049020d` | Pick helper interact check | Residual |
| `FUN_00925820` `0x00925cef` | Hover/pick companion | Residual |
| `FUN_008a81a0` `0x008a846f` | Secondary (trade-ish UI) | Residual |
| `UI_BuildItemTooltipStats` `0x00847b2e` | Truthy early tooltip branch | Residual (no stack arg in decomp) |
| `0x00861496`, `0x0090e11e` | Secondary | Residual |

---

## 8. Gaps / open

1. ~~Per-call-site ECX character provenance (IfInteractable)~~ **Closed** — `client+0xE98`.
2. Remaining 9 xrefs: load site for ECX (often local player / same `+0xE98` pattern expected, unproven).
3. Which requirement types implement non-trivial `vtable+0x40` (vs `+0x38` / `+0x44`).
4. Runtime capture: multi-active objectives → first-wins order on wire.
5. Product type name of `client+0xE98` (role sealed: character with active-obj hash).

**Verdict:** Control flow, helper `+0x40` arity, return id, and **primary wire path** are **High**. Residual is **non-primary call-site this** and **eval implementers**, not the walk itself. **accept-with-gaps.**
