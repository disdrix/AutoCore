# Review A (reconstruction fidelity): `aa_0091a350` Client_InteractWorldClick_SoftCastAlt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a350` |
| **VA** | `0x0091a350`–`0x0091a54a` inclusive (**507 B** / `0x1FB`) |
| **Canonical name** | `Client_InteractWorldClick_SoftCastAlt_Inferred` |
| **Ghidra name** | `FUN_0091a350` |
| **Prior scaffold** | `FUN_0091a350` (2026-07-23 trio) |
| **Rejected misname** | free `void` / ECX-thiscall-on-entry / ItemPickup clear-select owner / primary UseObject hub |
| **Review date** | `2026-08-05` (MEGA-033 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0091a350_Client_InteractWorldClick_SoftCastAlt_Inferred.md` |
| **System** | interaction-activation |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `read_memory` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` on call site. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Non-drop alternate** of dualed **`Client_InteractWorldClickHub`** (`0x00925820`):

```text
Client_InteractWorldClickHub
  … modal gates …
  if DAT_00d1a860 == 0:
      MOV ESI, EDI          ; ESI = client this
      CALL FUN_0091a350     ; OWN — return its bool
  else:
      drop-destroy modal OR ray + soft-cast hit-list walk
```

Body:

1. Gate `client->vtbl+0x3D8()`; fail → **0**.
2. `client+0x558 = -1.0f` (`DAT_00aaa668`); `client+0xA32 = 0`; `vtbl+0x478()`.
3. If select `client+0x758` non-null → `Ui_ResolveEntityNameColor_Inferred` (ECX=entity).
4. If global char soft-cast `entity+0x106` → clear `+0x107`; optional type-2 FX via `FUN_007a0120`.
5. Return **1**.

Soft-cast / clear-select **alternate** relative to hub drop + ray arms — does **not** itself store `select=0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-033 append) | `raw/aa_0091a350_FUN_0091a350.md` |
| Annotated | `raw/aa_0091a350_FUN_0091a350.annotated.md` |
| Clean | `reconstructed-exact/Client_InteractWorldClick_SoftCastAlt_Inferred.cpp` |
| Clean twin | `reconstructed-exact/FUN_0091a350.cpp` |
| Function record | `functions/aa_0091a350_FUN_0091a350.md` |
| Named record | `functions/aa_0091a350_Client_InteractWorldClick_SoftCastAlt_Inferred.md` |
| Live | decompile ≡ scaffold CF; body 507 B; 1 CALL xref; ESI this at call site |
| Parent hub | dualed `Client_InteractWorldClickHub` (W17-C) |
| Name-color | dualed `Ui_ResolveEntityNameColor_Inferred` (`0x00930fc0`, WQ9D-J) |
| FX spawn | residual `FUN_007a0120` |

---

## 3. Signature (sealed)

```c
// ESI = Client* (caller-established); no stack args; bare RET; bool AL
uint8_t Client_InteractWorldClick_SoftCastAlt_Inferred(void /* ESI */);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ESI** (`MOV EAX,[ESI]`; call site `MOV ESI,EDI` @ `0x00925956`) | **Confirmed** |
| stack args | none | **Confirmed** |
| return | **AL** 0/1 (`B0 01` / `32 C0`) | **Confirmed** |
| cleanup | bare **RET** (`C3`) at both exits | **Confirmed** |
| align | `AND ESP,0xFFFFFFF0`; `SUB ESP,0x1C` | **Confirmed** |

**Note:** Decompiler `void` + `unaff_ESI` is wrong for porting — assembly + parent call site seal ESI client.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| vtbl+0x3D8 gate; JZ fail | **Yes** | **Confirmed** |
| +0x558 = -1.0f; +0xA32=0; vtbl+0x478 | **Yes** | **Confirmed** |
| select+0x758 → name-color | **Yes** (JZ skip) | **Confirmed** |
| soft-cast +0x106 → clear +0x107 | **Yes** | **Confirmed** |
| body+0x284 → FUN_007a0120 type 2 | **Yes** | **Confirmed** |
| success AL=1 / fail AL=0 | **Yes** | **Confirmed** |

### Constants

| Site | Value | Conf |
|---|---|---|
| `DAT_00aaa668` | **-1.0f** (`00 00 80 BF`) | **Confirmed** `read_memory` |
| FX 0.4f / 1.0f / 3.0f | `0x3ECCCCCD` / `0x3F800000` / `0x40400000` | **Confirmed** |
| FX id | `0x61` | **Confirmed** |
| FX type | `param` pack `0,2,8` (type **2** beam path in callee) | **High** |

### Field map

| Offset | Role | Conf |
|---|---|---|
| `client+0x548` | FX float arg | **Confirmed** |
| `client+0x558` | float cancel write (−1.0f) | **Confirmed** |
| `client+0x758` | select entity* | **Confirmed** |
| `client+0xA32` | byte clear | **Confirmed** |
| `entity+0x106` / `+0x107` | soft-cast gate / clear | **Confirmed** |
| `entity+0x284` | body/visual* | **Confirmed** |

---

## 5. Callers / callees

| Kind | Value | Conf |
|---|---|---|
| Callers | **1** — `FUN_00925820` / `Client_InteractWorldClickHub` | **Confirmed** |
| Xrefs | **1** UNCONDITIONAL_CALL @ `0x00925958` | **Confirmed** |
| Callees | `FUN_00930fc0`, `FUN_007a0120`, vtbl `+0x3D8`, vtbl `+0x478` | **Confirmed** |

### Call-site (parent)

```text
0092594e  CMP byte ptr [DAT_00d1a860], AL
00925954  JNZ 0x00925974          ; drop / ray path
00925956  MOV ESI, EDI            ; ESI = client this
00925958  CALL 0x0091a350         ; OWN
0092595d  … SEH restore / RET 8   ; return OWN bool to hub caller
```

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF / ABI / sole hub caller | **Confirmed** | disasm + xrefs + call-site |
| Non-drop alternate role | **High** | `DAT_00d1a860==0` gate |
| Soft-cast secondary clear + type-2 FX | **High** | +0x106/+0x107 + callee type 2 |
| Live ≡ raw CF | **High** | decompile match |
| Not select-slot zero owner | **Confirmed** | no store to +0x758; no `FUN_0093e120` |
| Product vtbl / flag English | **Inferred** | open |
| Runtime | **Open** | no Launcher |

---

## 7. Gaps

1. Product English for vtbl `+0x3D8` / `+0x478`, `+0xA32`, float `+0x558`, `DAT_00d1a860`.
2. Full dual of `FUN_007a0120` (FX host / arg dictionary residual).
3. Whether name-color local is dead (buffer not stored after resolve) — preserve call order.
4. Runtime click routing vs drop/ray arms.
5. Bit-exact / differential deferred.

**Verdict:** **accept-with-gaps** — OWN CF/ABI/caller/constants sealed; product English + FX dual + runtime open.
