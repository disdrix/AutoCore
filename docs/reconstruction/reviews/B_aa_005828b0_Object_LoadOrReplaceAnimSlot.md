# Review B (skeptical / adversarial): `aa_005828b0` `Object_LoadOrReplaceAnimSlot`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005828b0` |
| **VA** | `0x005828b0` |
| **Canonical name** | `Object_LoadOrReplaceAnimSlot` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005828b0_Object_LoadOrReplaceAnimSlot.md` |
| **System** | `client::special-event` / visual anim |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `this` is special-event object | Call sites load ECX from visual fields (`+0x10`/`+0x24`), not event base | **Falsified** event-this |
| 2 | `ret 8` / 2 stack args | Epilogue `C2 0C 00`; 3 pushes | **Falsified** |
| 3 | Appends without replace | Non-null slot → remove + delete + zero before new | **Falsified** append-only |
| 4 | Fixed slot count 3 | Index is free int; callers use 1/2/3 only | **Attack fails** as "hardcoded 3 in body" |
| 5 | Always succeeds if controller set | Load `FUN_0074ee40` can return `<0` → 0 | **Falsified** always-success |
| 6 | Duration from loaded `.anm` resource | `FUN_0079a110` reads `DAT_00b04c74+0x238` | **Falsified** resource-duration claim |
| 7 | Decompiler "delete does not return" aborts CF | MSVC `operator_delete` pattern; success path continues in real binary | **Attack fails** as CF break |
| 8 | Product name proven | Structural only from behavior | **Agree Open** |
| 9 | Scaffold invents CF | Live ≡ raw | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall `ret 0xC` + visual this | **Confirmed** | Wrong object / stack crash |
| Replace + 0x78 + load + add | **Confirmed** | Broken airlift FX |
| Return 1/0 | **Confirmed** | Callers ignore return today but contract holds |
| Flag `+0x4c` write | **Confirmed** | Wrong loop/wrap behavior if mis-set |
| Product names / duration policy English | **Open** | Docs only |
| Orphan slot if load fails after store | **High** as raw CF | Leak / stale slot — do not "fix" in clean without evidence |

---

## 3. Cross-check against raw / live / bytes

CF narrative matches decompile:

```
if !controller: return 0
if slot[i]: Remove; teardown; delete; slot[i]=0
slot[i] = new(0x78)+ctor
resolve path; if load < 0: return 0
timing(0, globalDur); slot.flag=arg; Add; return 1
```

### Fail-after-store trap

Store of the new slot pointer **precedes** `FUN_0074ee40`. On load failure the function returns `0` **without** clearing `slot[i]`. Clean must preserve that order (not invent rollback) unless runtime proves otherwise.

### Special-event wrapper trap

TeleportIn/Out construct a special-event object and a separate visual (`GiveItemByCbid(0xadc)`). This unit runs on the **visual**. AutoCore ports must not call it with the event shell as `this`.

### Airtlift path strings (callers, not body)

- `obj_f_inc_mov_01_airlift_at.anm` (slot 1)
- `obj_f_inc_mov_01_airlift_aut.anm` (slot 2)
- `obj_f_inc_mov_01_airlift_at2.anm` (slot 3)

Body is path-agnostic.

---

## 4. Surviving contract for AutoCore

```
ok = Object_LoadOrReplaceAnimSlot(visual, slotIndex, path, flag):
  requires visual.controller != null
  replaces existing slot[slotIndex] if any
  allocates 0x78 anim slot, loads path, sets timing from global clock float
  writes flag to slot+0x4c
  registers with controller
  returns 1 or 0

AutoCore must NOT:
  - pass special-event shell as this
  - assume ret 8 / two args
  - skip replace teardown
  - invent resource-local duration without new evidence
  - "fix" load-fail leak without runtime proof
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Load/replace anim slot on visual | **Agree Confirmed** |
| thiscall ret 0xC / controller+slots | **Agree Confirmed** |
| accept-with-gaps | **Agree** |
| Structural name `Object_LoadOrReplaceAnimSlot` | **Agree** structural; product **Open** |
| Fail-after-store residual | **Agree** as gap (High CF, intentional unknown) |

---

## 6. Open questions

1. Product English for controller / slot / flag.
2. Duration global policy meaning.
3. Whether any non-airlift caller exists (static xrefs: only three functions).
4. Runtime golden for load-fail path.

**Verdict:** **accept-with-gaps** — adversarial pass on ABI/CF; residuals are naming + fail-path product intent + runtime.
