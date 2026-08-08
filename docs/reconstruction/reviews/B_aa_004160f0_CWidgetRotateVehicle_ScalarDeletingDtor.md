# Review B (skeptical / adversarial): `aa_004160f0` CWidgetRotateVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004160f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9I-F) |
| **Counterpart** | `reviews/A_aa_004160f0_CWidgetRotateVehicle_ScalarDeletingDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete-object dtor body | **Falsified** — body only calls `FUN_00416110` then optional free |
| 2 | This is a vector deleting dtor | **Falsified** — no array count / no `operator_delete[]` |
| 3 | Same ABI as complete (`00416110`) | **Falsified** — scalar is thiscall+flags; complete is stack-this `RET 4` only |
| 4 | Always frees heap | **Falsified** — bit0 gate |
| 5 | Must be vtbl[0] to be a dtor | **Falsified** — MSVC places new virtual dtor after base virtuals; slot +0x0C holds this VA; CF is pure scalar-dtor |
| 6 | Host is CWndVehicle | **Falsified** — sibling `004160d0` is CWndVehicle; this host is CWidgetRotateVehicle |
| 7 | Ghidra noreturn truncates | **Falsified** — full 31 B reaches epilogue |
| 8 | Complete dtor frees members | **Falsified** — `FUN_00416110` only rewrites vtbl to base |
| 9 | Product name unproven | **Falsified** — COL → `.?AVCWidgetRotateVehicle@@`; ctor installs `00a6ff94` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting vs complete body | **High** | Wrong port layering |
| flags bit0 gate | **High** | Leak / free non-heap |
| RET 4 | **High** | Stack corruption |
| Slot +0x0C vs [0] | **High** | Wrong vtbl wiring if assumed [0] |
| Product RTTI name | **High** | Naming residual closed |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_004160f0 (DATA @ 00a6ffa0 = PTR_LAB_00a6ff94[+0x0C]):
push esi
mov  esi, ecx
push esi
call FUN_00416110          ; complete: *this = PTR_LAB_00a9bbe8; ret 4
test byte ptr [esp+8], 1
je   skip
push esi
call operator_delete
add  esp, 4
skip:
mov  eax, esi
pop  esi
ret  4
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. Extra `PUSH ESI` vs sibling `004160d0` seals stack-this complete ABI.

---

## 4. Surviving contract for AutoCore

```
// Port scalar deleting only:
void* CWidgetRotateVehicle_ScalarDeletingDtor(void* self, uint8_t flags) {
  CWidgetRotateVehicle_CompleteDtor(self);  // FUN_00416110 — stack this
  if (flags & 1) operator_delete(self);
  return self;
}
// Virtual dtor slot at PTR_LAB_00a6ff94[+0x0C]; ret 4
// Do not assume vtbl[0]; base methods occupy earlier slots.
```

---

## 5. Verdict

**accept** — adversarial probes falsified; sealed contract holds. Terminal **false**.
