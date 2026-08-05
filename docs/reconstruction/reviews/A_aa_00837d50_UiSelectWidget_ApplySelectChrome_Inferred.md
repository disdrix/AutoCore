# Review A (reconstruction fidelity): `aa_00837d50` UiSelectWidget_ApplySelectChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00837d50` |
| **VA** | `0x00837d50`–`0x00837dc1` |
| **Canonical name** | `UiSelectWidget_ApplySelectChrome_Inferred` |
| **Ghidra name** | `FUN_00837d50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00837d50_UiSelectWidget_ApplySelectChrome_Inferred.md` |
| **System** | `interaction-activation` / client select-target UI chrome |
| **Verdict** | **accept-with-gaps** — ESI/EAX ABI, field `+0x518`, vtbl chain, child float path sealed |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Shared **select-widget chrome applicator** used by select-panel refresh twins (`FUN_00893580` widget at `panel+0x54c`, `FUN_008b2470` at `+0x520`, ctor path `FUN_008b27f0`, plus `FUN_00944d50` and orphan call sites).

Given **ESI = widget*** and **EAX = select/state value**:

1. Store `EAX` at **`widget+0x518`**.
2. `widget->vtbl[+0xd0]()` (thiscall, no stack arg) → byte in **AL**.
3. `widget->vtbl[+0xcc](1)` then `widget->vtbl[+0x444]()` then `widget->vtbl[+0xcc](AL)`.
4. If **`widget+0x53c` (child*) non-null** and **`+0x518 != 0`**: child `vtbl[+0x3c8]()` → float; child `vtbl[+0x3b0](float)`.
5. **Tail-jump** `widget->vtbl[+0x34c]()` (redraw/invalidate).

**Not** a network send, **not** select-target resolver, **not** packet dispatch.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00837d50_FUN_00837d50*`, `reconstructed-exact/FUN_00837d50.cpp` |
| Live decompile | Ghidra HTTP `decompile_function` `0x00837d50` (2026-07-29) ≡ raw body |
| Assembly | `disassemble_function` full body (prefer over decompiler `param_1`/`unaff_*` noise) |
| Callers | `FUN_00893580`, `FUN_008b2470`, `FUN_008b27f0`, `FUN_00944d50` (+ xrefs @ `0x009254e0`, `0x00925527`, `0x00893cab`) |
| Parent duals | `A_aa_00893580_*`, `A_aa_008b2470_*` |

**Not performed:** `disassemble_bytes`, Launcher, runtime UI capture, product RTTI names.

---

## 3. ABI (SEALED from assembly)

| Slot | Role | Evidence |
|------|------|----------|
| **ESI** | widget* (`this`) | all body stores/calls use ESI; callers `mov esi,[panel+off]` |
| **EAX** | select/state value written to `+0x518` | `mov [esi+0x518],eax`; callers `mov eax,ebx` |
| stack | none from sealed callers | no stack args at `00893580`/`008b2470` call sites |
| return | via tail `jmp [vtbl+0x34c]` | no local `ret` |

```c
// custom register ABI
void UiSelectWidget_ApplySelectChrome_Inferred(void);
// ESI = NDUI widget*, EAX = select/state (non-zero vs zero gates child float path)
```

Decompiler `__fastcall FUN_00837d50(undefined4 param_1)` is **misleading**: body never consumes a true ECX formal; `param_1` is a decompiler artifact. Prefer ESI/EAX contract.

---

## 4. Control flow (assembly ≡ intent)

```
push ecx                         ; local byte slot
[esi+0x518] = eax
al = widget.vtbl[+0xd0]()        ; thiscall
[esp] = al
widget.vtbl[+0xcc](1)
widget.vtbl[+0x444]()
widget.vtbl[+0xcc]([esp])        ; restore/apply prior byte
if ([esi+0x53c] != 0 && [esi+0x518] != 0):
  f = child.vtbl[+0x3c8]()
  child.vtbl[+0x3b0](f)
add esp, 4
jmp widget.vtbl[+0x34c]          ; tail redraw
```

| Offset | Role |
|-------:|------|
| `+0x518` | select/state dword (from EAX) |
| `+0x53c` | optional child widget* for float apply |
| vtbl `+0xd0` | query byte (enable-ish) |
| vtbl `+0xcc` | set flag/byte (called with 1, then with prior AL) |
| vtbl `+0x444` | intermediate configure |
| vtbl `+0x3c8` / `+0x3b0` | child get-float / set-float |
| vtbl `+0x34c` | invalidate/redraw (common UI family) |

---

## 5. Callers (sealed pattern)

| Site | Parent | Setup |
|---|---|---|
| `0x0089358d` | `UiSelectPanel_RefreshWidget_At54c` | `ESI=[EDI+0x54c]`, `EAX=EBX` |
| `0x008b247d` | twin at `+0x520` | same with `+0x520` |
| `0x008b287f` | `FUN_008b27f0` ctor/init | `ESI=[EDI+0x520]`, `EAX` from global |
| `0x00944f4c` / `0x00944f6f` | `FUN_00944d50` | dual calls |
| `0x009254e0`, `0x00925527`, `0x00893cab` | xrefs (no function wrap) | residual |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ESI=widget, EAX→`+0x518` | **Confirmed** | bytes |
| vtbl chain `+0xd0/+0xcc/+0x444/+0xcc` then optional child | **Confirmed** | bytes |
| Tail `+0x34c` | **Confirmed** | `jmp [edx+0x34c]` |
| Select-panel chrome helper (not net) | **High** | parent duals |
| Product meaning of EAX / vtbl names | **Open** | residual |
| Exact arity of `+0xcc` (1 vs 2 stack words) | **Probable** | pushes one formal each call |
| Orphan xref contexts | **Open** | no function metadata |

---

## 7. Gaps

1. Product class / vtbl names.
2. Semantic name for EAX beyond "select/state from EBX".
3. Child at `+0x53c` product role (alpha? progress?).
4. Orphan call sites at `0x009254e0` family.
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — register ABI + chrome sequence sealed for select UI porting.
