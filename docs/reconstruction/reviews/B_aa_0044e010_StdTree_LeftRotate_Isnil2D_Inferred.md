# Review B (skeptical / adversarial): `aa_0044e010` StdTree_LeftRotate_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e010` |
| **VA** | `0x0044e010` |
| **Canonical name** | `StdTree_LeftRotate_Isnil2D_Inferred` |
| **Review date** | `2026-08-05` (WQ9K-I dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + analyze/xrefs + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is **right** rotate | **Falsified** — promotes **right** child of X (left-rotate definition) |
| 2 | isnil/color at +0x31/+0x30 | **Falsified** — nil guard **`+0x2D`** only (`80 7A 2D 00`) |
| 3 | Same as isnil29 rotate `004192a0` | **Falsified** — different VA family; peers use this pair with StringKey erase/insert |
| 4 | Fastcall / no stack cleanup | **Falsified** — three **`RET 4`** exits; map on stack |
| 5 | Stack-only formals (no ECX) | **Falsified** — call sites `MOV ECX,ESI` before CALL |
| 6 | Recolors nodes | **Falsified** — leaf has no color stores; callers write `+0x2C` around CALL |
| 7 | Only one caller | **Falsified** — **10** CALL xrefs / 4 parent funcs |
| 8 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
MOV EAX, [ECX+8]        // Y = X.right
MOV EDX, [EAX]
MOV [ECX+8], EDX        // X.right = Y.left
MOV EDX, [EAX]          // Y.left again
CMP BYTE PTR [EDX+0x2D], 0
JNZ skip
MOV [EDX+4], ECX        // Y.left.parent = X
skip:
// Y.parent = X.parent; root / left / right rewire
// Y.left = X; X.parent = Y
RET 4  (×3 paths)
```

Call-site (erase path example):

```text
MOV ECX, ESI
PUSH EDX              // map
CALL 0x0044e010
// nearby: color@+0x2C, isnil@+0x2D
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Left-rotate CF | **High** | tree corruption |
| isnil@+0x2D | **High** | wrong family merge |
| thiscall + RET 4 | **High** | stack smash |
| Caller set | **High** | missing specialization |
| Product English | Medium | naming only |

---

## 4. Surviving contract for AutoCore

```csharp
// Left-rotate node X in isnil@+0x2D map tree
void LeftRotate(Node x, MapShell map)
{
    var y = x.Right;
    x.Right = y.Left;
    if (!y.Left.IsNil) y.Left.Parent = x;
    y.Parent = x.Parent;
    if (x == map.Root) map.Root = y;
    else if (x == x.Parent.Left) x.Parent.Left = y;
    else x.Parent.Right = y;
    y.Left = x;
    x.Parent = y;
}
```

Port must use **isnil@+0x2D** pair with R-rotate `0042a840`, not isnil29 / isnil31 rotates.

---

## 5. Open questions

1. Product map English name.
2. WQ9K-J dual of right-rotate peer.
3. Runtime / differential.
