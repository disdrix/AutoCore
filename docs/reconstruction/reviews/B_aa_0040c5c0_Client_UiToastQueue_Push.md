# Review B (skeptical / adversarial): `aa_0040c5c0` Client_UiToastQueue_Push

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c5c0` |
| **VA** | `0x0040c5c0` |
| **Canonical name** | `Client_UiToastQueue_Push` (structural) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040c5c0_Client_UiToastQueue_Push.md` |
| **System** | `missions-progression` (shared UI toast) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **is** GiveMission / grants the mission | Body is only capacity math + POD copy / grow | **Falsified** — grant is `CVOGReaction_GiveMission`; this is post-pack enqueue |
| 2 | This plays `"gen_give_quest"` audio | Audio is separate call after push in GiveMission | **Falsified** |
| 3 | This formats `"Received Mission: …"` | sprintf/strncpy happen in **caller** before push | **Falsified** |
| 4 | Element size is something other than `0x98` | imul/sar divide by `0x98`; `ADD reg,0x98`; copy `0x26×4` | **Attack fails** — stride **Confirmed** |
| 5 | Success toast and modal fail helper are the same API | Craft: success → this VA; fail → `FUN_007fdfb0` | **Falsified** collapse |
| 6 | Ghidra `void` / no stack args is ABI truth | Bytes end **`ret 4`** (`C2 04 00`); every site `PUSH` element | **Falsified** bare-void model |
| 7 | Decompiler 5-arg `FUN_00404670` is the real signature | Callee body uses **3** formals; extra pushes dead + `ADD ESP,0x14` | **Overstated** parent decompile |
| 8 | Grow path `FUN_0040c720(&param_2, …)` means `this` is the element | Asm `MOV ECX,ESI` (queue) before call | **Falsified** — decompiler this-elision on grow |
| 9 | Exclusive to mission system | Craft, progress Action, input UI, etc. also call | **Falsified** exclusive-GiveMission |
| 10 | Deep-constructs non-POD (vtables, strings owning heap) | `FUN_00404710` pure dword copy | **Falsified** owning ctor |
| 11 | `this+0` is begin (release std::vector layout) | Body begin is **`*(this+4)`** | **Falsified** if ported as `_Myfirst@0` |
| 12 | Product name required to seal dual | No string/RTTI in this VA | **Agree leave structural** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride `0x98` / POD copy | **Confirmed** | Buffer overrun or short copy on port |
| begin/end/cap @ +4/+8/+0xC | **Confirmed** | Corrupts wrong queue fields |
| Fast vs grow branch | **Confirmed** | Missed realloc → silent drop or OOB write |
| `ret 4` / one element pointer arg | **Confirmed** | Stack imbalance in reimplemented callers |
| Role = toast queue push | **High** | Mis-wire as mission state mutation |
| ECX = entity(+0xA8)+0xE8C8 | **High** | Push into wrong object |
| Element field product English | **Tentative** (caller duals) | Wrong UI scale/color if re-packed |
| Product symbol | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-07-29).
read_memory @ 0x0040c5c0:
  begin = [ESI+4]; end=[ESI+8]; cap=[ESI+0xC]
  size/cap via magic imul for /0x98 (0x6BCA1AF3 pattern)
  fast: CALL FUN_00404670; ADD EDI,0x98; MOV [ESI+8],EDI; POP; POP; RET 4
  grow: MOV ECX,ESI; CALL FUN_0040c720; POP; POP; RET 4
callees: FUN_00404670, FUN_0040c720 only
xrefs: 12 (GiveMission, CompleteObjective, end-quest, craft success,
       progress toast Action, 5+ other UI, 2 code sites)
```

### GiveMission trap

Do **not** treat this VA as the grant. At `0x00532aeb`:

```
; pack local 0x98 toast (text, 0xffeee3d8, 2.0, 1.5, ids)
LEA  EDX, [ESP+…]
PUSH EDX
; ECX = *(*(char+4)+4 + char + 0xA8)
ADD  ECX, 0xE8C8
CALL Client_UiToastQueue_Push   ; 0x0040c5c0
; THEN audio gen_give_quest / Client_PlayNamedInterfaceSound
```

Outer grant / hash insert / objective ensure are **other** VAs.

### Craft trap

Status 0 → this push ("Item Created!"). Status 1–5 → `FUN_007fdfb0` fail modal path. Collapsing them loses the dual UI surface.

### Layout trap

Porting as `std::vector<T>` with `_Myfirst` at **offset 0** is wrong for this queue object: observed begin is **`+4`**. Element must remain **`0x98`** POD; do not assume `std::string` inside without caller proof (copy is blind dwords).

---

## 4. Surviving contract for AutoCore

```
Client_UiToastQueue_Push(queue, element) -> void
  queue layout: begin@+4, end@+8, capacity_end@+0xC
  element: POD sizeof 0x98 (caller fills text/color/floats/ids)
  if begin && size < capacity:
    memcpy-style construct at end (0x26 dwords); end += 0x98
  else:
    grow/reallocate via FUN_0040c720 / FUN_00403980; insert one
  // no return status; no audio; no mission state
```

Typical `this` recovery (caller pattern, not body):

```
obj = *(*(character+4)+4 + character + 0xA8)
queue = obj + 0xE8C8
```

---

## 5. Residual after dual

| Item | Status |
|------|--------|
| CF / ABI / stride | **Sealed Confirmed** |
| Toast-queue role | **Sealed High** |
| GiveMission-only identity | **Falsified** (shared helper) |
| Product name | Open |
| Element field English | Open (caller duals) |
| Queue owner class @ entity+0xA8 | Open |
| Runtime capture | Open |

**Verdict:** accept-with-gaps. Safe to call from mission/craft/progress ports as **push-only** helper.
