# Review B (skeptical / adversarial): `aa_008dd590` CDlgFirstTime_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_008dd590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008dd590_CDlgFirstTime_ctor.md` |
| **Live tools** | Ghidra `force_decompile` + `read_memory` + caller decompiles + dtor decompile (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | “Ctor only zeros memory; XML load is caller” | **Falsified** — body ends with `FUN_008dc970("i_d_first.xml")` → `NDUIWindow_ReloadInterface` |
| 2 | Object size unknown / “typical dialog 0x500” | **Falsified** — both callers `operator_new(0x5b0)` |
| 3 | Many callers / factory registry | **Falsified** — exactly **2** call sites (`0x0080183c`, `0x008c4134`) |
| 4 | Vtbl is still base dialog after ctor | **Falsified** — `*this = PTR_FUN_00a3d8b4` **after** `FUN_0087b890` which installed `PTR_FUN_00a58c6c` |
| 5 | `+0x54c` is a plain int zero | **Falsified** — `FUN_0040fb90` heap `0xC` circular node; dtor `operator_delete(this[0x153])` |
| 6 | `+0x4fc=0xf` / `+0x500=1` inherited from base only | **Falsified as “only base”** — base zeros both; **this ctor overwrites** to `0xf` / `1` |
| 7 | Ctor sends first-time flag packet | **Falsified** — no `Client_SendUpdateFirstTimeFlags` / tip-bit in this body (callers do) |
| 8 | Full `memset(this,0,0x5b0)` | **Falsified** — only base ctor + listed stores + `FUN_008dc1f0` block; mid-object NDUI base fields come from `FUN_0087b890`/`FUN_00792d20` |
| 9 | Dual A dword indices mis-scaled | **Survives** — Ghidra `param_1[n]` is dword index → byte `n*4`; `+0x519` is explicit byte address (not index) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name `CDlgFirstTime_ctor` + XML `i_d_first.xml` | **High** | Wrong UI skin |
| Size `0x5B0` | **High** | Heap overflow / under-alloc |
| Vtbl `0x00a3d8b4` | **High** | Wrong virtuals / dtor |
| Init order (base → vtbl → zeros → list → defaults → bulk → XML) | **High** | Use-before-init if reordered |
| `+0x54c` heap list head | **High** | Leak / double-free |
| `+0x544` tip-queue drain field | **High** (consumer); owner English **Probable** | Wrong queue clear in prefs path |
| `+0x52c=-1` tip-id none | **High** value; English **Probable** | Off-by-one tip display |
| Field English for bulk zero block | **Tentative** | Port layout comments only |
| ABI thiscall vs stack-this | **Probable** stack-first | Interop glue |

---

## 3. Cross-check: force_decompile ≡ raw ≡ clean CF

```
SEH;
FUN_0087b890(this, 0);          // base dialog
*this = PTR_FUN_00a3d8b4;       // class vtbl @ 0x00a3d8b4
[0x14e..0x151] = 0;             // +0x538..+0x544
[0x153] = FUN_0040fb90();       // +0x54c list head
[0x154] = 0;                    // +0x550
[0x13f]=0x0f; [0x140]=1;        // +0x4fc / +0x500
[0x14b]=-1; [0x14c]=0;          // +0x52c / +0x530
bytes +0x518,+0x519 = 0;
[0x143..0x145]=0;               // +0x50c..+0x514
FUN_008dc1f0();                 // bulk zero tip fields
FUN_008dc970("i_d_first.xml");  // load UI
return this;
```

`force_decompile` (2026-07-29) identical to raw capture body — no CF drift.

### Machine prologue (`read_memory` @ `0x008dd590`, 32B)

```
6a ff                 push -1
68 9b 70 9b 00        push LAB_009b709b
64 a1 00 00 00 00     mov  eax, fs:[0]
50                    push eax
64 89 25 00 00 00 00  mov  fs:[0], esp
51 53 56              push ecx / ebx / esi
8b 74 24 1c           mov  esi, [esp+0x1c]   ; this (stack)
33 db                 xor  ebx, ebx
53 56                 push 0 ; push this → FUN_0087b890
```

Hex head: `6aff689b709b0064a10000000050648925000000005153568b74241c33db5356`

---

## 4. Caller contracts (not owned, adversarial seal)

### `Client_MaybeShowFirstTimeTip` (`0x00801760`)

- Gate tip id / bitfield on char `+0xd30` **before** construct.
- Lazy: if `client+0x1164==0` → `new(0x5b0)` + **this ctor**.
- Post-ctor: vfunc show/queue (`+0x3d8`, `+0x46c`, `+0x450`, …) — **not** part of ctor body.

### `FUN_008c40a0` (msg `8` / `0x9c41`)

- Global `DAT_00d1b9a4` lazy singleton via **same ctor**.
- Drains `dlg[0x151]` (`+0x544`) with `Client_SetFirstTimeTipBit` loop — proves ctor zeroing of that slot is intentional empty queue.

Attack on “two independent dialog classes”: **same ctor symbol shared vtbl; different storage roots only.

---

## 5. Surviving contract for AutoCore

```
// Size sealed: 0x5B0
CDlgFirstTime* CDlgFirstTime_ctor(CDlgFirstTime* self)
{
  BaseDialogOrWindow_ctor(self, /*param=*/0);   // FUN_0087b890 → base vtbl then...
  self->vtbl = &PTR_FUN_00a3d8b4;               // 0x00a3d8b4

  self->pChild_538 = self->pChild_53c =
  self->pChild_540 = self->pQueue_544 = nullptr;

  self->pTipListHead_54c = EmptyCircularNode_new_0xC(); // FUN_0040fb90
  self->nTipListSize_550 = 0;

  self->nDialogFlags_4fc = 0x0f;
  self->nDialogMode_500  = 1;
  self->nTipId_52c       = -1;
  self->nTipIdAux_530    = 0;
  self->bState_518 = self->bState_519 = 0;
  self->z_50c = self->z_510 = self->z_514 = 0;

  CDlgFirstTime_ZeroTipFields(self);            // FUN_008dc1f0
  CDlgFirstTime_LoadInterface(self, "i_d_first.xml"); // FUN_008dc970
  return self;
}
```

Port notes:
- **Do not** skip XML load in ctor — retail always loads `i_d_first.xml` here.
- **Do not** memset entire `0x5B0` without base ctor — NDUI base owns lower layout.
- Tip-bit / `SendUpdateFirstTimeFlags` belong to **callers**, not ctor.
- Free path must delete `+0x54c` list head (dtor does).

---

## 6. Residual attacks (leave open)

1. Exact product type of `FUN_0040fb90` node (std::list vs custom intrusive).
2. Whether `+0x538..+0x540` are always widgets or sometimes other ptrs.
3. Full vtbl English beyond dtor + load slot.
4. Runtime show order vs ctor side effects of ReloadInterface.

**Verdict:** **accept-with-gaps** (ctor CF + size + vtbl + XML + list head sealed **High**; field English partial)
