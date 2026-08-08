# Review B (skeptical / adversarial): `aa_00403e90` StdTree_Lrotate_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403e90` |
| **VA** | `0x00403e90` |
| **Canonical name** | `StdTree_Lrotate_Isnil31_Inferred` |
| **Review date** | `2026-08-05` (WQ9L-B dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00403e90_StdTree_Lrotate_Isnil31_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is **right** rotate | **Falsified** — promotes **right** child of X (left-rotate definition) |
| 2 | isnil/color at +0x2D/+0x2C or +0x29/+0x28 | **Falsified** — nil guard **`+0x31`** only (`80 7A 31 00`) |
| 3 | Same as isnil29 rotate `004192a0` | **Falsified** — different VA / isnil offset; peers of erase isnil31 |
| 4 | Same as isnil2D rotate `0044e010` | **Falsified** — isnil@+0x2D peer family |
| 5 | Fastcall / no stack cleanup | **Falsified** — three **`RET 4`** exits; map on stack |
| 6 | ECX = tree / stack = node | **Falsified** — body reads `[ECX+8]` as X.right; call sites `MOV ECX,node` + `PUSH map` |
| 7 | Recolors nodes | **Falsified** — leaf has no color stores; callers write `+0x30` around CALL |
| 8 | Mission/NotifyActiveMission helper | **Falsified** — pure STL tree leaf; 5 tree rebalance xrefs |
| 9 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
MOV EAX, [ECX+8]        // Y = X.right
MOV EDX, [EAX]
MOV [ECX+8], EDX        // X.right = Y.left
MOV EDX, [EAX]          // Y.left again
CMP BYTE PTR [EDX+0x31], 0
JNZ skip
MOV [EDX+4], ECX        // Y.left.parent = X
skip:
// Y.parent = X.parent; root / left / right rewire
// Y.left = X; X.parent = Y
RET 4  (×3 paths)
```

Call-site (erase path example @ `0x00409062`):

```text
PUSH EBP                // map
MOV ECX, ESI            // node
CALL 0x00403e90
// nearby: color@+0x30, isnil@+0x31
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Left-rotate CF | **High** | tree corruption |
| isnil@+0x31 | **High** | wrong family merge |
| thiscall + RET 4; ECX=node | **High** | stack smash |
| Caller set | **High** | missing specialization |
| Product English | Medium | naming only |

---

## 4. Surviving contract for AutoCore

```csharp
// Left-rotate node X in isnil@+0x31 map tree (node size 0x38)
void LeftRotate(Node x, MapShell map)
{
    var y = x.Right;
    x.Right = y.Left;
    if (!y.Left.IsNil) y.Left.Parent = x;
    y.Parent = x.Parent;
    if (x == map.Head.Parent) map.Head.Parent = y;       // was root
    else if (x == x.Parent.Left) x.Parent.Left = y;
    else x.Parent.Right = y;
    y.Left = x;
    x.Parent = y;
}
// RET 4 at call boundary. Keep distinct from isnil29/isnil2D rotates and Rrotate 00403ee0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles. Residual product map English → **accept-with-gaps**.
