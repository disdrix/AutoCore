# Review B (skeptical / adversarial): `aa_0098fef0` GfxMesh_BuildNonInteriorEdgeIB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098fef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-F) |
| **Counterpart** | `reviews/A_aa_0098fef0_GfxMesh_BuildNonInteriorEdgeIB_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall mesh method | **Falsified** — two stack args; **RET 8** |
| 2 | Always returns 0 (decompiler ends on delete) | **Falsified** — success `MOV EAX,ESI` before RET 8 |
| 3 | Product name is gfxDeviceIB | **Falsified** — string is unlock diagnostic only; multi-stage mesh builder |
| 4 | Keeps interior edges (count==2) | **Falsified** — filter is **!= 2** |
| 5 | Edge key is ordered as stored | **Partial** — undirected pack uses min/max after compare |
| 6 | Face types only triangles | **Careful** — steps helper names triangle; types 4/5/6 only gated |
| 7 | Ghidra body end complete | **Careful** — success cleanup continues past catalog end; pad `CC` after final RET 8 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 / 2-arg ABI | **High** | Wrong port convention |
| Return clone vs 0 | **High** | Lost output mesh |
| Non-interior filter | **High** | Wrong topology extract |
| NestedHash family | **High** | Wrong bag layout |
| Product English | **Low** | Naming only |
| Vtable dispatch | **Med** | Call-site discovery |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + callees

- Prologue matches SEH + `[EBP+0xC]` mesh load.
- Fail path `0x0099020f`: `33C0 ... C2 08 00`.
- Success path ends `8BC6 ... C2 08 00`.
- Callee `FUN_00457ac0` sealed W34-E as NestedHash0x10 placement ctor (this unit is a **caller**, not the ctor).
- `FUN_0044b610` logs `gfxFirst.h` / `GetTriangleVertexSteps` — supports face-type stride model.

---

## 4. Surviving contract for AutoCore

```
// Port as stdcall-ish two-arg builder, not thiscall:
Mesh* BuildNonInteriorEdgeIB(void* ctx, Mesh* src) {
  if (!src || faceType∉{4,5,6}) return nullptr;
  NestedHash10 bag; NestedHash_Ctor_Sentinel0x10(&bag);
  // lock IB; count undirected edges; unlock
  // emit edges with count!=2 into line-list clone type=2
  return clone_or_null;
}
// Do not hard-name as gfxDeviceIB::Unlock.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, return value, edge filter, NestedHash, face gate. Residual product plates + Ghidra body range + write-loop register → **accept-with-gaps**.
