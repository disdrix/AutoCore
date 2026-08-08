# Review B (skeptical / adversarial): `aa_00832fa0` CWndWaypointIcon_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00832fa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-B) |
| **Counterpart** | `reviews/A_aa_00832fa0_CWndWaypointIcon_CompleteDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a scalar-deleting dtor | **Falsified** — no flags arg; installs vtbl; frees member then base; no free of `this` |
| 2 | This is a vector-deleting dtor | **Falsified** — no array count / no `operator_delete[]` |
| 3 | cdecl / stack this | **Falsified** — entry `MOV ESI,ECX` |
| 4 | Frees host heap | **Falsified** — bare `RET`; host free is scalar peer only |
| 5 | `operator_delete` is noreturn / truncates body | **Falsified** — `ADD ESP,4` then always-null `+0x488`, base call, `RET` |
| 6 | Always skips free of `+0x488` | **Falsified** — non-null path calls release + delete |
| 7 | Never nulls `+0x488` when was null | **Falsified** — store-zero is after the if (unconditional) |
| 8 | Product name remains Class_00a7000c only | **Falsified** — RTTI type_info **`.?AVCWndWaypointIcon@@`** at COL chain |
| 9 | Same base path as CWndVehicle complete | **Falsified** — this chains `FUN_007b5be0` directly; CWndVehicle uses `FUN_0078ca80` first |
| 10 | Same unit as scalar `00416350` | **Falsified** — scalar is thin complete-then-flags wrapper |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar/vector | **High** | Double-free / miss free |
| Vtbl + RTTI product name | **High** | Naming residual closed for this VA |
| Owned `+0x488` free-then-null | **High** | Leak / UAF |
| False-noreturn correction | **High** | Truncated port |
| Owned block product layout | **Open** | Residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_00832fa0 (CWndWaypointIcon complete):
// SEH; ESI = ECX
mov  dword ptr [ESI], 00a7000ch
mov  EDI, [ESI+488h]
test EDI, EDI
jz   skip_free
mov  ECX, EDI
call FUN_0096efd0
push EDI
call operator_delete
add  esp, 4
skip_free:
mov  dword ptr [ESI+488h], 0
mov  ECX, ESI
call FUN_007b5be0
; SEH restore; ret
```

Live decompile 2026-08-05 ≡ raw CF with noreturn warning corrected by bytes.  
`read_memory` COL `@0x00a70008` → `0x00ab5e08` → type_info `0x00affae4` → `.?AVCWndWaypointIcon@@`.  
vtbl[0] dword `@0x00a7000c` = `0x00416350` (scalar peer).

---

## 4. Surviving contract for AutoCore

```
// Port complete dtor only (not scalar):
void CWndWaypointIcon_CompleteDtor(void* self) {
  *(void**)self = &PTR_FUN_00a7000c;
  void* owned = *(void**)((char*)self + 0x488);
  if (owned) { FUN_0096efd0(owned); operator_delete(owned); }
  *(void**)((char*)self + 0x488) = nullptr; // always
  FUN_007b5be0(self);
}
// Do NOT operator_delete(self) here.
// Scalar peer: 0x00416350 (rename residual → CWndWaypointIcon_ScalarDeletingDtor)
```

---

## 5. Verdict

**accept-with-gaps** — adversarial probes on role/ABI/vtbl/RTTI/free-path falsified; owned-block English remains open. Terminal **false**.
